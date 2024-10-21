import re

def convert_function(func):
    func = func.replace('^', '**')  # Mengubah tanda '^' menjadi '**' untuk eksponen
    func = re.sub(r"(\d)(x)", r"\1*x", func)  # Mengubah angka dan variabel menjadi format perkalian (misal 2x -> 2*x)
    return func
