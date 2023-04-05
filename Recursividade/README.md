# Aula 2

## Recursividade

### Função/Modularização/

```c
// retorno nome (parametros);

int fatorial (int numero) {
	int retorno = 1;

	for(int i = numero; i > 1; i--) {
			retorno = retorno * i;
	}

	retorno = numero * fatorial(numero -1); //Função sendo chamada por ela mesma
	return retorno;
}

```

A ideia da recursividade é uma função sendo chamada por ela mesma

**Qual a utilidade da recursividade?** 

- Consegue restringir a busca sem precisar recorrer à todos os dados, ou seja, **otimiza** o processo de busca

<aside>
💡 Pensamento orientado a otimização
</aside>


Exercício: 

- Implementar uma função com **recursividade**
- Cálculo fatorial
- Operação atômica

```c
1! = 1;
2! = 2 * 1!
3! = 3 * 2!
4! = 4 * 3!
5! = 5 * 4!
```

### Uma solução iterativa

Segundo [este artigo](http://linguagemc.com.br/recursividade-em-c/), em muitos casos uma solução iterativa gasta menos memória do que a recursividade em si.

**O que é um algoritmo iterativo?**

```sql
#include <stdio.h>

int factorial(int number){
    // caso padrao
    if (number == 1) {
        return 1;
    }
    
    //caso recursivo
    return number * factorial(number - 1);
}    

int main()
{
    int result = factorial(30);
    printf("%d", result);

    return 0;
}
```
