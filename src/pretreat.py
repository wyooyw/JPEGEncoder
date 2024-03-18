# -*- coding: utf-8 -*-
"""
Created on Sat Jun  5 00:49:24 2021

@author: wyo
"""

import cv2
import numpy as np
output = open("image.txt","w")
img = cv2.imread("seventeen.jpg" ,1)

img = img.transpose(2,0,1)
c,h,w = img.shape
output.write("%d %d\n"%(w,h))

for i in range(c):
    for j in range(h):
        for k in range(w):
            output.write("%d "%img[c-i-1,j,k]);
        output.write("\n");
        

output.close();
