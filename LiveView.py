import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mplt
import re,time,math

#Compensation Factors

s0v=-0.06780992625743963
s1v=-0.08560980873824499
s2v=-0.09001045583834316

maxPot=800
minPot=300

playback=True
playbackFile="Testdata/Test1_10.3.csv"
f=None;

usePot=True

if(playback):
    f=open(playbackFile)
    f.readline()



def nextInput():
    if playback:
        txt=f.readline()
    if (txt==""):
        return None
    txt = re.split(",",txt[:-1])
    if(len(txt)!=8):
        return None
    txt=(int(txt[0]),int(txt[1]),int(txt[2]),int(txt[3]),int(txt[4]),int(txt[5]),int(txt[6]),int(txt[7]))
    return (txt)

def getAngle(l00,l01,l10,l11,l20,l21,p0,p1):
    if(usePot):
        p=(p0+p1)*0.5
        p=p-minPot
        p=p/(maxPot-minPot)
        p=p*math.pi
        p=p-0.5*math.pi
        return p

    




import sys, pygame

pygame.init()


size = width, height = 300, 400

speed = [2, 2]

black = 0, 0, 0
yellow = 255,255,0
white= 255,255,255
blue = 0,0,255
red= 255,0,0
green=0,255,0


screen = pygame.display.set_mode(size)

midpoint=(width//2,(height-100)//2)
l =80


lastTime=time.time()
(l00,l01,l10,l11,l20,l21,p0,p1)=nextInput()
while True:

    for event in pygame.event.get():

        if event.type == pygame.QUIT: sys.exit()


    if(time.time()-lastTime>0.003):
        while(time.time()-lastTime>0):
            try:
                (l00,l01,l10,l11,l20,l21,p0,p1)=nextInput()
            except:
                break
            lastTime=lastTime+0.003
        
    screen.fill(black)

    a=getAngle(l00,l01,l10,l11,l20,l21,p0,p1)
    print(a*180//math.pi)
    a=a+math.pi


    l1=math.cos(math.pi/2 - a/2)*l+math.cos(a/2)*l
    l2=math.cos(math.pi/2 + a/2)*l+math.cos(-a/2)*l
    points=[0,0,0,0,0,0,0,0]
    points[0]=(midpoint[0],midpoint[1]+l1)
    points[4]=(midpoint[0],midpoint[1]-l1)
    points[2]=(midpoint[0]+l2,midpoint[1])
    points[6]=(midpoint[0]-l2,midpoint[1])

    points[1]=(midpoint[0]-math.sin(a/2)*l,midpoint[1]+math.cos(math.pi/2 - a/2)*l)
    points[7]=(midpoint[0]+math.sin(a/2)*l,midpoint[1]-math.cos(math.pi/2 + a/2)*l)

    points[3]=(midpoint[0]-math.sin(a/2)*l,midpoint[1]-math.cos(math.pi/2 - a/2)*l)
    points[5]=(midpoint[0]+math.sin(a/2)*l,midpoint[1]-math.cos(math.pi/2 - a/2)*l)


    pygame.draw.polygon(screen,white,points,width=5)

    # calc sensor values
    s0=(l01-l00)-(l00*s0v)
    s1=(l11-l10)-(l10*s1v)
    s2=(l21-l20)-(l20*s2v)

    w= (width-50)/3
    maxHeight=80
    maxValue=180
    
    sp0=pygame.Rect(0*w+25+10,380-(s0*maxHeight)//maxValue,w-20,(s0*maxHeight)//maxValue)
    sp1=pygame.Rect(1*w+25+10,380-(s1*maxHeight)//maxValue,w-20,(s1*maxHeight)//maxValue)
    sp2=pygame.Rect(2*w+25+10,380-(s2*maxHeight)//maxValue,w-20,(s2*maxHeight)//maxValue)

    screen.fill(red,rect=sp0)
    screen.fill(green,rect=sp1)
    screen.fill(blue,rect=sp2)

    maxRadius=30

    la=(math.pi/2)-(math.pi-a/2-math.pi/4)
    las=math.pi/7
    lastart=la-las
    lastop=la+las
    r=200
    dx1=r/2
    dy1=r/2


    arcbox=pygame.Rect(points[1][0]-dx1,points[1][1]-dy1,r,r)

    pygame.draw.arc(screen,yellow,arcbox,lastart,lastop,width=100)
    pygame.draw.circle(screen,blue,points[3],(s2*maxRadius)//maxValue)
    pygame.draw.circle(screen,green,points[5],(s1*maxRadius)//maxValue)
    pygame.draw.circle(screen,red,points[7],(s0*maxRadius)//maxValue)


    pygame.display.flip()
