#Imports
from my_package.model import ImageCaptioningModel
from my_package.data import Dataset, Download
from my_package.data.transforms import FlipImage, RescaleImage, BlurImage, CropImage, RotateImage
# from my_package.data.dataset import Dataset
# from my_package.data.transforms import blur,crop,flip,rescale,rotate
import numpy as np
from PIL import Image
import os
#import jsonlines


def experiment(annotation_file, ncaptioner, transforms, outputs):
    '''
        Function to perform the desired experiments

        Arguments:
        annotation_file: Path to annotation file
        captioner: The image captioner
        transforms: List of transformation classes
        outputs: Path of the output folder to store the images
    '''

    #Create the instances of the dataset, download
    
    download = Download()
    dataset = Dataset(annotation_file,transforms)


    #Print image names and their captions from annotation file using dataset object
    
    #print(dataset.__len__())
    
    for i in range(0,dataset.__len__()):
        
        
        img = dataset.__getann__(i)
        #print("Image name: ")
        print(img["file_name"])
        print(img["captions"])
        
        
    #Download images to ./data/imgs/ folder using download object
    
    # with jsonlines.open(annotation_file) as reader:
    #     for obj in reader:
            
    #         path = outputs+i+'.jpg'
    #         Download(path,obj["url"])
    
    for i in range(0,dataset.__len__()):
        
        img = dataset.__getann__(i)
        
        path = outputs+str(i)+'.jpg'
        download(path,img["url"])
    
    


    #Transform the required image (roll number mod 10) and save it seperately
    #roll number mod 10 = 1, file path = ./data/imgs/1.jpg
    #Storing the required transformed images in ./data/transformed
    
    #parent_dir = os.getcwd()
    transform_path = './data/transformed/'
    os.mkdir(transform_path)
    count=0
    
    for i in range(0,len(transforms)):
        
        transformed_img = transforms[i](Image.open('./data/imgs/1.jpg'))
        
        path = transform_path+'transform_'+str(i+1)+'.jpg'
        transformed_img = transformed_img.save(path)
        
        if(i==0):
            print(captioner('./data/imgs/1.jpg',num_captions=3)) # Original image caption
        
        print(captioner(path,num_captions=3))
        
        count+=1
                
    #Get the predictions from the captioner for the above saved transformed image
    
    # for i in range(count):
    #     path = transform_path+'transform_'+str(i)+'.jpg'
    
    #     captioner(path,num_captions=3)


def main():
    captioner = ImageCaptioningModel()
    #experiment('./data/annotations.jsonl', captioner, [FlipImage(), BlurImage(1), RescaleImage((1280,960)), RescaleImage((320,240)), RotateImage(270), RotateImage(45), CropImage((10,10))], './data/imgs/') # Sample arguments to call experiment()
    experiment('./data/annotations.jsonl', captioner, [CropImage((10,10))], './data/imgs/') # Sample arguments to call experiment()


if __name__ == '__main__':
    main()