# ProjetoFinal
Projeto Final PDS2 - UFMG
Integrantes: Artur Xavier Nascimento, Pedro Bacelar Rigueira, Caio Souza Grossi, Luiz Eduardo Gonçalves da Silveira e Artur Fonseca de Souza
# Apresentação do problema 

O programa em questão aborda a gestão de uma locadora de filmes, sendo necessário implementar um sistema capaz de controlar o estoque de filmes, cadastrar e remover clientes, realizar operações de aluguel e devolução, além de imprimir registros de clientes e filmes. O sistema também deve permitir a leitura de informações de um arquivo de estoque para facilitar o carregamento inicial de filmes.

# Visão Geral da Solução:

A nossa solução é estruturada em classes, sendo as principais classes Filme, DVD, Fita, Cliente e Locadora. Assim sendo, a classe abstrata Filme serve como base para as classes específicas DVD e Fita, que herdam características comuns e implementam métodos específicos e, a classe Locadora coordena as operações entre clientes e o estoque de filmes.

A leitura do arquivo de estoque é feita pela função ler_Arquivo_de_Estoque, que utiliza a classe Filme para criar instâncias de DVD e Fita conforme o tipo de filme especificado no arquivo. As operações de aluguel e devolução são gerenciadas pelos métodos alugar_Filme e devolver_Filme, que atualizam o estoque e registram as transações em um arquivo de log.

# Principais Dificuldades Encontradas:

Uma das principais dificuldades foi lidar com a complexidade das operações envolvendo múltiplas classes, especialmente no controle de estoque e na interação com o sistema de arquivos para a leitura do arquivo de estoque e o registro das operações de log. Além disso, a gestão dinâmica de memória para evitar vazamentos foi um ponto de atenção, especialmente no destrutor da classe Locadora, onde é necessário liberar os recursos alocados para clientes e filmes.
