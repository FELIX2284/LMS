import cv2
import numpy as np

car_cascade = cv2.CascadeClassifier('cars.xml')

parking_slots =[
    (115,250,95,200),
    (355,250,95,200),
    (600,250,95,200),
    
]
def detect_cars_in_raw(block,raw):
    x,y,w,h=raw
    raw_block = block[y:y+h, x:x+w]
    cars= car_cascade.detectMultiscale(raw_block, 1.1,1)
    return len(cars)>0

def process_parking_slot_image(image_path):
    img =cv2.imread(image_path)
    block =cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    for raw in parking_slots:
        occupied = detect_cars_in_raw(block,raw)
        x,y,w,h=raw
        if occupied:
           color = (0,0,255)
        status ="Already Occupied"
    else:
          color = (0,255,0)
          status = ("Empty Slot Available")
          cv2.rectangle(img, (x,y),(x+w,y+h), color,2)
          cv2.putText (img, status, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, color, 2, cv2.LINE_AA)

          cv2.imshow('parking slot',img)
          cv2.waitkey(0)
          cv2.destroyALLWINDOWS()

          output_path = image_path .replace('.jpg','_prosessed.jpg')
          cv2.imwrite(output_path,img)

          print(f'proccesed image saved as:{output_path}')

    image_path=r'C:\Users\felix\Desktop\CAT2\gettyimages-82848685-1024x1024.jpg'
    process_parking_slot_image(image_path)
