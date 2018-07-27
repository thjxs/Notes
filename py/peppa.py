#!/usr/bin/env python3
# -*- coding:utf-8 -*-
from PIL import Image
import sys
file_name = sys.argv[1]
ascii_char = list("$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. ")
length = len(ascii_char)
img = Image.open(file_name)
(width,height)=img.size
img = img.resize((int(width*0.2),int(height*0.15)))
print(img.size)
def convert(img):
	img = img.convert("L")
	txt = ""
	for i in range(img.size[1]):
		for j in range(img.size[0]):
			gray = img.getpixel((j,i))
			unit = 256.0 / length
			txt += ascii_char[int(gray / unit)]
		txt += '\n'
	return txt
def convert1(img):
	txt = ""
	for i in range(img.size[1]):
		for j in range(img.size[0]):
			r,g,b = img.getpixel((j,i))
			gray = int(r * 0.299 + g * 0.587 + b * 0.114)
			unit = (256.0+1)/length
			txt += ascii_char[int(gray/unit)]
		txt += '\n'
	return txt

txt = convert(img)
f = open("peppa.md", "w")
f.write(txt)
f.close()
