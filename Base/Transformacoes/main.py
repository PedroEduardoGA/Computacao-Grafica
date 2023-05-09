from Transformacoes import *

#Arquivo para chamar as funcoes:
print("Inicializando o Transformador de imagens!")

print('Realizando transformacao de translacao!')
a, b = transalacao(4, 5, 3, -4)
print(f'Após transformacao de transalacao -> X: {round(a, 3)} - Y: {round(b, 3)}')

print('Realizando transformacao de escala!')
a, b = escala(4, 5, 0.5, 0.25)
print(f'Após transformacao de escala -> X: {round(a, 3)} - Y: {round(b, 3)}')

print('Realizando transformacao de rotacao!')
a, b = rotacao(1, 2, 45)
print(f'Após transformacao de rotacao -> X: {round(a, 3)} - Y: {round(b, 3)}')

print('Realizando transformacao de cisalhamento!')
a, b = cisalhamento(0, 2, 1, 0)
print(f'Após transformacao de cisalhamento -> X: {round(a, 3)} - Y: {round(b, 3)}\n')

#2ª Parte
print('Realizando transformacao de translacao usando coordenadas homogeneas!')
a, b = translacaoHomogenea(4, 5, 3, -4)
print(f'Após transformacao de transalacao Homogenea -> X: {round(a, 3)} - Y: {round(b, 3)}')

print('Realizando transformacao de escala usando coordenadas homogeneas!')
a, b =  escalaHomogenea(4, 5, 0.5, 0.5)
print(f'Após transformacao de escala Homogenea -> X: {round(a, 3)} - Y: {round(b, 3)}\n')

print('Realizando Rotacao em relacao a um ponto P!')
a, b = rotacaoEmP(4, 5, 45, 6, 10)
print(f'Após transformacao de rotacao em relacao a um ponto -> X: {round(a, 3)} - Y: {round(b, 3)}\n')

print('Realizando Escala em relacao a um ponto P!')
a, b = escalaEmP(6, 10, 0.5, 0.5, 4, 5)
print(f'Após transformacao de escala em relacao a um ponto -> X: {round(a, 3)} - Y: {round(b, 3)}\n')

print('Realizando Escala em relacao ao centro geometrico!')
a, b =  escalaCentroGeometrico(6, 10, 6, 7.2, 2, 2)
print(f'Após transformacao de escala em relacao ao Centro Geometrico -> X: {round(a, 3)} - Y: {round(b, 3)}\n')