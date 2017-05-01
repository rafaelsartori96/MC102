import os
import shutil


numeroLista = int(input('Digite o número da lista: '))
# Precisamos achar o diretório da lista:
listaDiretorio = os.path.join(os.getcwd(), 'Lista ' + str(numeroLista))

if not os.path.exists(listaDiretorio):
    os.makedirs(listaDiretorio)
    print('Criando pasta "' + str(listaDiretorio) + '"')
print('\n')

# Para sabermos até qual exercício fazemos
exercicios = range(int(input('Entre com o número do primeiro exercício: ')), int(input('Entre com o número do último exercício: ')) + 1)

# Determinando como devemos copiar
exercicioBase = os.path.join(os.getcwd(), 'modelo.c')
while not os.path.exists(exercicioBase):
    print('\nNão encontramos "' + str(exercicioBase) + '"!')
    nome = input('Entre com o nome do arquivo de exercício base (com extensão) ou digite \"tentar novamente\": ')
    print('\n')
    # Se o input não foi 'tentar novamente', usamos o novo nome de exercício
    if not nome.lower() == 'tentar novamente'.lower():
        exercicioBase = os.path.join(os.getcwd(), nome)

for exercicio in exercicios:
    exercicioDiretorio = os.path.join(listaDiretorio, "Lista{0}_ex{1:02d}.c".format(numeroLista, exercicio))
    # Fazer a cópia, se o arquivo não existir
    if not os.path.exists(exercicioDiretorio):
        print('Criando "' + str(exercicioDiretorio) + '"')
        shutil.copy2(str(exercicioBase), str(exercicioDiretorio))
print('\nPronto! Todos os arquivos foram criados!')
