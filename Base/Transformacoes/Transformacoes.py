import math
import numpy as np

#---------------------------------------PrimeiraParte---------------------------------------
def transalacao(x, y, Tx, Ty):
    newX = x + Tx
    newY = y + Ty
    return (newX, newY)

def escala(x, y, Tx, Ty):
    newX = x * Tx
    newY = y * Ty
    return (newX, newY)

def rotacao(x, y, angulo):
    # Converte o ângulo de graus para radianos
    angulo = math.radians(angulo)
    
    # Calcula as novas coordenadas x e y usando a fórmula de rotação
    newX = (x * np.cos(angulo) - y * np.sin(angulo))
    newY = (x * np.sin(angulo) + y * np.cos(angulo))
    
    return (newX, newY)

def cisalhamento(x, y, Kx, Ky):
    # Calcula as novas coordenadas x e y usando a fórmula de cisalhamento
    newX = x + (Kx*y)
    newY = y + (Ky*x)
    
    return (newX, newY)

#Reflexao em relação ao eixo X
def reflexaoEmX(x, y):
    #Matriz da formula
    matrizTransf = np.matrix([[1, 0, 0], [0, -1, 0], [0, 0, 1]])
    
    coordsHomogenea = np.matrix([[x], [y], [1]])
    resultado = np.matmul(matrizTransf, coordsHomogenea) #Multiplica matrizes

    newX = resultado[0, 0]
    newY = resultado[1, 0]
    return (newX, newY)

#Reflexao em relação ao eixo Y
def reflexaoEmY(x, y):
    #Matriz da formula
    matrizTransf = np.matrix([[-1, 0, 0], [0, 1, 0], [0, 0, 1]])

    coordsHomogenea = np.matrix([[x], [y], [1]])
    resultado = np.matmul(matrizTransf, coordsHomogenea) #Multiplica matrizes

    newX = resultado[0, 0]
    newY = resultado[1, 0]
    return (newX, newY)

#Reflexao em relação a linha y = x
def reflexaoLinhaYx(x, y):
    #Matriz da formula
    matrizTransf = np.matrix([[0, 1, 0], [1, 0, 0], [0, 0, 1]])

    coordsHomogenea = np.matrix([[x], [y], [1]])
    resultado = np.matmul(matrizTransf, coordsHomogenea) #Multiplica matrizes

    newX = resultado[0, 0]
    newY = resultado[1, 0]
    return (newX, newY)

#Reflexao em relação a linha y = -x
def reflexaoLinhaYMenosX(x, y):
    #Matriz da formula
    matrizTransf = np.matrix([[0, -1, 0], [-1, 0, 0], [0, 0, 1]])

    coordsHomogenea = np.matrix([[x], [y], [1]])
    resultado = np.matmul(matrizTransf, coordsHomogenea) #Multiplica matrizes

    newX = resultado[0, 0]
    newY = resultado[1, 0]
    return (newX, newY)

#---------------------------------------SegundaParte---------------------------------------
def translacaoHomogenea(x, y, Tx, Ty):
    #Matriz da formula
    matrizTransf = np.matrix([[1, 0, Tx], [0, 1, Ty], [0, 0, 1]])
    
    coordsHomogenea = np.matrix([[x], [y], [1]])
    resultado = np.matmul(matrizTransf, coordsHomogenea)

    newX = resultado[0, 0]
    newY = resultado[1, 0]
    return (newX, newY)

def escalaHomogenea(x, y, Sx, Sy):
    #Matriz da formula
    matrizTransf = np.matrix([[Sx, 0, 0], [0, Sy, 0], [0, 0, 1]])
    
    coordsHomogenea = np.matrix([[x], [y], [1]])
    resultado = np.matmul(matrizTransf, coordsHomogenea)

    newX = resultado[0, 0]
    newY = resultado[1, 0]
    return (newX, newY)

def rotacaoHomogenea(x, y, angulo):
    # Converte o ângulo de graus para radianos
    angulo = math.radians(angulo)
    
    matrizTransf = np.matrix([[np.cos(angulo), -np.sin(angulo), 0], [np.sin(angulo), np.cos(angulo), 0], [0, 0, 1]])

    coordsHomogenea = np.matrix([[x], [y], [1]])
    resultado = np.matmul(matrizTransf, coordsHomogenea)

    newX = resultado[0, 0]
    newY = resultado[1, 0]
    return (newX, newY)

def rotacaoEmP(Px, Py, angulo, x, y):
    # Converte o ângulo de graus para radianos
    angulo = math.radians(angulo)

    cos0 = math.cos(angulo)
    sen0 = math.sin(angulo)

    matrizTransf = np.array([[cos0, -sen0, Px-(Px*cos0)+(Py*sen0)], [sen0, cos0, Py-(Py*cos0)-(Px*sen0)], [0, 0, 1]])

    coordsHomogenea = np.matrix([[x], [y], [1]])
    resultado = np.matmul(matrizTransf, coordsHomogenea)
    
    newX = resultado[0, 0]
    newY = resultado[1, 0]
    return (newX, newY)

def escalaEmP(x, y, Sx, Sy, Px, Py):
    #Matriz da formula
    matrizTransf = np.matrix([[Sx, 0,  Sx*Px], [0, Sy, Sy*Py], [0, 0, 1]])
    
    coordsHomogenea = np.matrix([[x], [y], [1]])
    resultado = np.matmul(matrizTransf, coordsHomogenea)

    newX = resultado[0, 0]
    newY = resultado[1, 0]
    return (newX, newY)

def escalaCentroGeometrico(x, y, Gx, Gy, Sx, Sy):
    #Matriz da formula
    matrizTransf = np.matrix([[Sx, 0, -Gx], [0, Sy, -Gy], [0, 0, 1]])
    
    coordsHomogenea = np.matrix([[x], [y], [1]])
    resultado = np.matmul(matrizTransf, coordsHomogenea)

    newX = resultado[0, 0]
    newY = resultado[1, 0]
    return (newX, newY)