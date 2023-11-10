#Imports
import jsonlines
from PIL import Image
import os
import numpy as np

class Dataset(object):
    '''
        A class for the dataset that will return data items as per the given index
    '''

    def __init__(self, annotation_file, transforms=None):
        '''
            Arguments:
            annotation_file: path to the annotation file
            transforms: list of transforms (class instances)
                        For instance, [<class 'RandomCrop'>, <class 'Rotate'>]
        '''
        
        self.annotation_flie = annotation_file
        self.transforms = transforms
     

    def __len__(self):
        '''
            return the number of data points in the dataset
        '''
        count=0
        
        with jsonlines.open(self.annotation_flie) as reader:
            for obj in reader:
                count+=1
        count
        return count
        

    
    def __getann__(self, idx):
        '''
            return the data items for the index idx as an object
        '''
        count=0

        with jsonlines.open(self.annotation_flie) as reader:
            for obj in reader:
                if(count==idx):
                    return obj
                count+=1

        
 

    def __transformitem__(self, path):
        '''
            return transformed PIL Image object for the image in the given path
        '''
        
        return self.transforms(Image.open(path))