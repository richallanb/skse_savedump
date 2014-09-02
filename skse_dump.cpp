#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>
using namespace std;

int main (int argc, char * argv[]) {
	char skse_data[255][255];
	
	if (argc != 3) {
		cout << "Wrong number of arguments\n";
		return 0;
	}
	cout << "Opening " << argv[1] << " as skse save and " << argv[2] << " as NMM configuration\n";
	ifstream skse (argv[1]);
	ofstream imp (argv[2]);
	imp << "GameMode=Skyrim\n\n";
	skse.seekg(47);
	char cur='A';
	char cwrd[255];
	int wrdi=0;
	int sksei=0;
	bool done = 0;
	while (sksei < 255 && !done) {
		
		while (cur=skse.get())
			cwrd[wrdi++] = cur;
		
		cwrd[wrdi-1] = '\0';
		if (!strcmp(cwrd+wrdi-5, "RNEM"))  {
			cwrd[wrdi-5] = '\0';
			done = 1;
		}
		strcpy (skse_data[sksei++], cwrd);
		imp << skse_data[sksei-1] << "=1" << "\n";
		cout << sksei  << ". " << skse_data[sksei-1] << "\n";

		wrdi=0;
	}
	imp << "\n";
	skse.close();
	imp.close();
	return 0;
}
