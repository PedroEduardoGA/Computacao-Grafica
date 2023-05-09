from Algoritmos import *
import pygame
import sys

white = (255, 255, 255)

def putPixel(screen, points):
    for posicao, (x, y) in enumerate(points):
        screen.set_at((int(x), int(y)), white)

pygame.init()  # inicialização
window = pygame.display.set_mode((500, 500))  # cria a janela de exibição
pygame.display.set_caption("Plotagem")

#Chamar algoritmo desejado
#points = DDA(2, 4, 12, 8)
#points = bresenham(4, 8, 21, 13)
points = bresenhamCircunferencia(50, 50, 25)

putPixel(window, points)
pygame.display.update()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:  # fechar a janela no x
            pygame.quit()
            sys.exit()