*This project has been created as part of the 42 curriculum by khebert.*

khebert / TwaKy Project !

**ENGLISH VERSION**


**Description :**

- Push_Swap mainly consists of sorting numbers via two piles, A and B, A being the main one, the sorted result will have to be returned in A. Pile B is only present to be able to do the number sorting but that’s not all. Push_swap is the first project of our 42-year curriculum that involves creating an algorithm.

**Instructions :**

- In order to be able to test the project, you can follow the following steps: 
    - In the ft_main. c, replace the existing hand with the following hand, so that you can display the result:

        int main(int argc, char **argv)
        {
            t_stack *stack_a;
            t_stack *stack_b;
    
            if (argc >= 2)
            {
                stack_a = ft_parse_args(argc, argv);
                stack_b = NULL;
                if (is_sorted(stack_a))
                    return (0);
                if (argc == 3)
                    two_args(&stack_a);
                else if (argc == 4)
                    three_args(&stack_a);
                else if (argc == 6)
                    five_args(&stack_a, &stack_b);
                else
                    ft_turk_algo(&stack_a, &stack_b);
                ft_print_stack(stack_a)
                free_stack(&stack_a);
                if (stack_b)
                    free_stack(&stack_b);
            }
            return (0);
        }
    
    - Use the command: make to compile the program entirely, then you will be able to see a new file named : pushswap which is the result of our make, to use it you only have to do the following command: . /pushswap 6 7 8 3 2 89 (you can modify the arguments..);

    - You will then see the sorted numbers displayed on your terminal with the operations performed.

**Resources :**

- To begin with, I would like to talk about AI. I obviously used it because it is a very useful tool of our generation when used properly. Talking about his use, he helped me a lot not with the code but in structuring my project. That is to say, knowing where I am, what remains for me to do, etc., I asked him to follow up on my project with me and I helped myself with his project plan to move forward! He hasn’t done any code on this project. You can also notice that it is not the AI that made them, I used it as a tool and it was really GREAT!

- I also used this site: https://42-cursus.gitbook.io/guide/2-rank-02/push_swap. It was useful for me on the first section which is simply the algorithm to be able to understand what an algorithm was, having never used this before this project I needed to understand its usefulness and how it works!


**FRENCH VERSION**


**Description :**

- Push_Swap consiste principalement à trier des nombres via deux piles, la A et la B, la A étant la principale, le résultat trié devra être retourné dans A. La pile B est uniquement présente pour pouvoir réaliser le tri de nombres, mais ce n'est pas tout. Push_swap est le premier projet de notre cursus à 42 qui consiste à réaliser un algorithme.

**Instructions :**

- Afin de pouvoir tester le projet, vous pouvez suivre les étapes suivantes : 
    - Dans le ft_main.c, remplacez le main existant par le main suivant, afin de pouvoir afficher le résultat :

        int main(int argc, char **argv)
        {
            t_stack *stack_a;
            t_stack *stack_b;
    
            if (argc >= 2)
            {
                stack_a = ft_parse_args(argc, argv);
                stack_b = NULL;
                if (is_sorted(stack_a))
                    return (0);
                if (argc == 3)
                    two_args(&stack_a);
                else if (argc == 4)
                    three_args(&stack_a);
                else if (argc == 6)
                    five_args(&stack_a, &stack_b);
                else
                    ft_turk_algo(&stack_a, &stack_b);
                ft_print_stack(stack_a)
                free_stack(&stack_a);
                if (stack_b)
                    free_stack(&stack_b);
            }
            return (0);
        }
    
    - Utilisez la commande : make pour compiler le programme entièrement, ensuite vous pourrez voir apparaître un nouveau fichier nommé : pushswap qui est le fruit de notre make, pour l'utiliser vous n'aurez qu'à faire la commande suivante : ./pushswap 6 7 8 3 2 89 (vous pouvez modifier les arguments..);

    - Vous verrez ensuite les nombres triés s'afficher sur votre terminal avec les opérations effectuées.

**Resources :**

- Pour commencer, je voudrais parler de l'IA. Je l'ai bien évidemment utilisée car c'est un outil de notre génération très utile lorsqu'il est bien utilisé. En parlant de son utilisation, il m'a beaucoup aidé non pas sur le code mais dans la structuration de mon projet, C'est-à-dire savoir où j'en suis, savoir ce qu'il me reste à faire, etc., je lui ai demandé de suivre avec moi mon projet et je me suis aidé de son projet plan pour avancer ! Il n'a réalisé aucun code sur ce projet. Vous pouvez d'ailleurs remarquer que ce n'est pas l'IA qui les a réalisés, je l'ai utilisé comme un outil et c'était vraiment TOP !

- J'ai aussi utilisé ce site : https://42-cursus.gitbook.io/guide/2-rank-02/push_swap. Il m'a été utile sur la première rubrique qui est tout simplement l'algorithme pour pouvoir comprendre ce qu'était un algorithme, n'ayant jamais utilisé ça avant ce projet j'avais besoin de comprendre son utilité et son fonctionnement !
