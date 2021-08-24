#include <iostream>
#include <sstream>
#include <fstream>

#include "tf_classifier.h"

using namespace std;
using namespace mnist;

bool read_features(std::istream& stream, Classifier::features_t& features) 
{
    std::string line;
    std::getline(stream, line);

    features.clear();
    std::istringstream linestream{line};
    double value;
    while (linestream >> value) 
    {
        features.push_back(value);
    }
    return stream.good();
}



int main(int argc, char** /*argv[]*/)
{
	if (argc != 3)
	{
		cout << "Usage: fashio_mnist <test> <model>";
		return -1;
	}

	const char* model = "saved_model";
	const char* test_file = "test.csv";

	auto clf = TfClassifier{model, 28, 28};

	auto features = TfClassifier::features_t{};

	std::ifstream test_data{test_file};
	
	if(!test_data) return -1;

	float right_answer = 0;
	float all_answer = 0;

	while(true) 
	{
		size_t y_true;
		test_data >> y_true;

		if(!read_features(test_data, features)) 
		{
			break;
		}

		cout << "features.size() " << features.size() << std::endl;

		auto y_pred = clf.predict(features);
		
		if(y_true == y_pred) ++right_answer;
		++all_answer;
	}

	std::cout << right_answer / all_answer;

	return 0;
}
