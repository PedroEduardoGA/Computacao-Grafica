import math

def DDA(x, y, x2, y2):
    points = []
    step = math.fabs(x2-x)

    if(math.fabs(y2-y) > step):
        step = math.fabs(y2-y)

    xinc = (x2-x) / step
    yinc = (y2-y) / step

    while(x < x2):
        points.append((int(x), int(y)))
        x = x+xinc
        y = y+yinc
    
    return points

def bresenham(x, y, x2, y2):
    points = []
    if(x2 > x):
        xinc = 1
    else:
        xinc = -1

    if(y2 > y):
        yinc = 1
    else:
        yinc = -1

    DeltaX = abs(x2 - x)
    DeltaY = abs(y2 - y)

    if(DeltaX >= DeltaY):
        #1º octante
        p = 2*DeltaY - DeltaX
        p2 = 2*DeltaY
        xy2 = 2*(DeltaY - DeltaX)
        while(x != x2):
            x = x+xinc
            if(p < 0):
                p = p+p2
            else:
                p = p+xy2
                y = y+yinc

            points.append((x, y))
    else:
        #2º octante
        p = 2*DeltaX - DeltaY
        p2 = 2*DeltaX
        xy2 = 2*(DeltaX - DeltaY)
        while(y != y2):
            y = y+yinc
            if(p < 0):
                p = p+p2
            else:
                p = p+xy2
                x = x+xinc

            points.append((x, y))

    return points

def bresenhamCircunferencia(xC, yC, r):
    points = []
    x= 0
    y= r
    p= 3-2*r
    
    while(x <= y):
        points = addPontosOctantes(points, xC, yC, x, y)

        if(p < 0):
            p = p+(2*x)+6
        else:
            p = p+4*(x - y)+10
            y-=1

        x+=1

    return points

def addPontosOctantes(points, xC, yC, x, y):
    points.append((xC+x, yC+y))#1º
    points.append((xC+y, yC+x))#2º
    points.append((xC+y, yC-x))#3º
    points.append((xC+x, yC-y))#4º
    points.append((xC-x, yC-y))#5º
    points.append((xC-y, yC-x))#6º
    points.append((xC-y, yC+x))#7º
    points.append((xC-x, yC+y))#8º
    
    return points
