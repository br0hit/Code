#Imports
from PIL import Image
import random

class CropImage(object):
    '''
        Performs either random cropping or center cropping.
    '''

    def __init__(self, shape, crop_type='center'):
        '''
            Arguments:
            shape: output shape of the crop (h, w)
            crop_type: center crop or random crop. Default: center
        '''
        
        self.shape = shape
        self.crop_type = crop_type

    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)
        '''
                

        if(self.crop_type == 'center'):
            
            img_width, img_height = image.size
        
        else:
            
            img_width, img_height = image.size
            img_width = int(random.randint(0,img_width-self.shape[1]))
            img_height = int(random.randint(0,img_height-self.shape[0]))
            
        left = int(img_height)/2 - self.shape[1]/2
        top = int(img_width)/2- self.shape[0]/2
        right = int(img_height)/2 + self.shape[1]/2
        bottom = int(img_width)/2 + self.shape[0]/2

        
        im_crop = image.crop((left,right,top,bottom))
        #test
        
        return im_crop
            
            
            
            
            
            
            
            
        
        
        
        

        

 
