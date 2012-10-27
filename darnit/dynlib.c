#include "darnit.h"


void *dynlibOpen(const char *fname) {
	char *fname_n;
	if (fname == NULL) return NULL;
	
	#ifdef _WIN32
		fname_n = utilPathTranslate(fname);
		HINSTANCE *lib;

		lib = malloc(sizeof(HINSTANCE));
		*lib = LoadLibrary(fname_n);
	#else
		void *lib;

		fname_n = malloc(strlen(fname) + 3);
		sprintf(fname_n, "./%s", fname);
		lib = dlopen(fname_n, RTLD_NOW | RTLD_GLOBAL);
	#endif
	free(fname_n);
	return lib;
}


void *dynlibSymbolGet(void *lib, const char *symbol) {
	if (lib == NULL || symbol == NULL) return NULL;
	#ifdef _WIN32
		HINSTANCE *libh = lib;
		void *sym;

		sym = GetProcAddress(*libh, symbol);
		return sym;
	#else
		void *sym;
		
		sym = dlsym(lib, symbol);
		return sym;
	#endif
}


void *dynlibClose(void *lib) {
	if (lib == NULL) return NULL;
	#ifdef _WIN32
		HINSTANCE *libh = lib;

		FreeLibrary(*libh);
		free(lib);
		return NULL;
	#else
		dlclose(lib);
		return NULL;
	#endif
}