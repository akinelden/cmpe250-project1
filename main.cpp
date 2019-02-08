#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>

#include <chrono>
#include "Customer.h"
#include "Simulation0.h"
#include "Simulation1.h"

using namespace std;

template <class Container>
void split1(const string& str, Container& cont)
{
	istringstream iss(str);
	copy(istream_iterator<string>(iss),
		istream_iterator<string>(),
		back_inserter(cont));
}

void HandleNewRecord(CUSTOMER *& c, vector<CUSTOMER*>& arrivals)
{
	if (arrivals.empty()) {
		arrivals.push_back(c);
		return;
	}
	vector<CUSTOMER*>::iterator it = arrivals.end();
	it--;
	while ((*it)->GetArrivalTime() > c->GetArrivalTime() && it != arrivals.begin())
		it--;
	it++;
	arrivals.insert(it, c);
}

void PrintRecord(const Record& r) {
	cout << r.waiting_time << " " << r.missed_flight << endl;
}

void PrintOut(const Record& r, ofstream& myfile) {
	myfile << r.waiting_time << " " << r.missed_flight << endl;
}

int main(int argc, char* argv[]) {

	auto begin = chrono::high_resolution_clock::now();
	
	if (argc != 3) {
		cout << "Run the code with the following command: ./project2 [input_file] [output_file]" << endl;
		return 1;
	}

	//cout << "input file: " << argv[1] << endl;
	//cout << "output file: " << argv[2] << endl;
	
	vector<CUSTOMER*> arrival_list;

	ifstream infile(argv[1]);
	string line;
	vector<string> input;
	getline(infile, line);
	vector<string> numbers;
	split1(line, numbers);
	int N = stoi(numbers[0]);
	int L = stoi(numbers[1]);
	int S = stoi(numbers[2]);

	int a, f, l, s;
	bool v, lu;
	for (int i = 0; i < N; i++) {
		getline(infile, line);
		vector<string> words;
		split1(line, words);
		a = stoi(words[0]);
		f = stoi(words[1]);
		l = stoi(words[2]);
		s = stoi(words[3]);
		v = (words[4] == "V");
		lu = (words[5] == "L");
		CUSTOMER* temp = new CUSTOMER(a, f, l, s, lu, v);
		HandleNewRecord(temp, arrival_list);
	}


	ofstream myfile;
	myfile.open(argv[2]);

	SIMULATION0* s1 = new SIMULATION0(0, 0, L, S, &arrival_list);
	s1->Start();
	Record r1 = s1->Results();
	PrintOut(r1, myfile);
	PrintRecord(r1);

	SIMULATION1* s2 = new SIMULATION1(0, 0, L, S, &arrival_list);
	s2->Start();
	Record r2 = s2->Results();
	PrintOut(r2, myfile);
	PrintRecord(r2);

	SIMULATION0* s3 = new SIMULATION0( 0, 1, L, S, &arrival_list);
	s3->Start();
	Record r3 = s3->Results();
	PrintOut(r3, myfile);
	PrintRecord(r3);

	SIMULATION1* s4 = new SIMULATION1( 0, 1, L, S, &arrival_list);
	s4->Start();
	Record r4 = s4->Results();
	PrintOut(r4, myfile);
	PrintRecord(r4);

	SIMULATION0* s5 = new SIMULATION0( 1, 0, L, S, &arrival_list);
	s5->Start();
	Record r5 = s5->Results();
	PrintOut(r5, myfile);
	PrintRecord(r5);

	SIMULATION1* s6 = new SIMULATION1( 1, 0, L, S, &arrival_list);
	s6->Start();
	Record r6 = s6->Results();
	PrintOut(r6, myfile);
	PrintRecord(r6);

	SIMULATION0* s7 = new SIMULATION0( 1, 1, L, S, &arrival_list);
	s7->Start();
	Record r7 = s7->Results();
	PrintOut(r7, myfile);
	PrintRecord(r7);

	SIMULATION1* s8 = new SIMULATION1( 1, 1, L, S, &arrival_list);
	s8->Start();
	Record r8 = s8->Results();
	PrintOut(r8, myfile);
	PrintRecord(r8);

	myfile.close();

	delete s1, s2, s3, s4, s5, s6, s7, s8;
	s1 = s3  = s5  = s7 = nullptr;
	s2 = s4 = s6 = s8 = nullptr;
	for (int i = 0; i < arrival_list.size(); i++) {
		delete arrival_list[i];
	}

	auto stop = chrono::high_resolution_clock::now();
	auto duration3 = chrono::duration_cast<chrono::microseconds>(stop - begin);
	//cout << "Total passed time: " << duration3.count() << endl;

	
	return 0;
}