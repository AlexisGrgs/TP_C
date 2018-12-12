#include "master.h"

int main()
{
	/*int plateau[NB_LIGNES][NB_COLONNES + 2];
	int solution[NB_COLONNES];
	int proposition[NB_COLONNES];
	int bp = 0;
	int mp = 0; 
	int nbcoup = 0;*/
	int flags=IMG_INIT_JPG|IMG_INIT_PNG;
	int initted= 0;
	int width = 400;
	int height = 550;
	int running = 1;
	initted = IMG_Init(flags);
	
	SDL_Window   * window;
	SDL_Event event;
	SDL_Renderer *renderer;

	SDL_Surface *image = NULL;
	image=IMG_Load("image.png");
	
	if(!image) {
		printf("IMG_Load: %s\n", IMG_GetError());
	}
	
	if((initted&flags) != flags)
	{
    printf("IMG_Init: Impossible d'initialiser le support des formats JPG et PNG requis!\n");
    printf("IMG_Init: %s\n", IMG_GetError());
	}
	
	if (TTF_Init() != 0)
	{
		fprintf(stderr, "Erreur d'initialisation TTF : %s\n", TTF_GetError());
	}
	
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
    	fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
    	return EXIT_FAILURE;
	}
	else
	{
		window = SDL_CreateWindow("SDL2 Programme 0.1", SDL_WINDOWPOS_CENTERED, 		  SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);

		if (window == 0)
		{
			fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
			/* on peut aussi utiliser SLD_Log() */
		}
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED ); /*  SDL_RENDERER_SOFTWARE */
	if (renderer == 0) {
		 fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
		 /* faire ce qu'il faut pour quitter proprement */
	}
		}
		while (running) {

		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_WINDOWEVENT:
					printf("window event\n");
					switch (event.window.event)
					{
						case SDL_WINDOWEVENT_CLOSE:
							printf("appui sur la croix\n");
							break;
						case SDL_WINDOWEVENT_SIZE_CHANGED:
							width = event.window.data1;
							height = event.window.data2;
							printf("Size : %d%d\n", width, height);
						default:
							printf("R");
							afficherEcran(renderer, image);
					}
					break;
				case SDL_MOUSEBUTTONDOWN:
					printf("Appui :%d %d\n", event.button.x, event.button.y);
					//afficherEcran() ?
					break;
				case SDL_QUIT :
					printf("on quitte\n");
					running = 0;
			}
		}
		SDL_Delay(1); //  delai minimal
	}
	
	/*if(argc > 1) initialisation ramdom manuellement 
	{
		srand(atoi(argv[1]));
	}
	
	else
	{
		srand(time(NULL));
	}

	printf("Bienvenue dans le mastermind :\n");

	initialiser_plateau(plateau);
	initialiser_solution(solution);
		
	do
	{
		bp = 0, mp = 0; // remise a zero des valeurs a trouve.
		vocabCouleur();
		saisie(proposition);
		compiler_proposition(proposition, solution, &bp, &mp);
		MajPlateau(plateau, proposition, bp, mp, nbcoup);
		affichagePlateau(plateau);
		nbcoup++;
	
	}while(bp != 4 && nbcoup < 10);
	
	resultat(bp, solution);*/
	SDL_FreeSurface(image);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	
	return 0;	
}
