from PIL import Image
import requests
from io import BytesIO
import json


class Download(object):
    '''
        A class for helping in dowloading the required images from the given url to the specified path
    '''

    def __call__(self, path, url):
        '''
            Arguments:
            path: download path with the file name
            url: required image URL
        '''
        
        response = requests.get(url)
        
        if response.status_code:
            fp = open(path,'wb')
            fp.write(response.content)
            fp.close()
        
        # img = Image.open(requests.get(url,stream=True).raw)
        # img.save(path)
            
        
        
            


