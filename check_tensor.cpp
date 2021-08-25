#include "check_tensor.h"
#include "tf_classifier.h"

#include <sstream>
#include <fstream>

using namespace std;
using namespace mnist;

bool ReadFeatures(std::istream& stream, Classifier::features_t& features) 
{
     std::string line;
     std::getline(stream, line);

     features.clear();
     std::istringstream linestream{line};
     double value;

     while (true) 
     {
          linestream.get(); // read ','
          linestream >> value;
          if(!linestream) break;
          features.push_back(value);
     }

     return stream.good();
}

float GetTensorAccuracy(const char* model, const char* test_file)
{
	auto clf = TfClassifier{model, 28, 28};

	auto features = TfClassifier::features_t{};

	std::ifstream test_data{test_file};
	
	if(!test_data) return -1;

	float right_answer = 0;
	float all_answer = 0;

	for(;; ++all_answer) 
	{
		size_t y_true;
		test_data >> y_true;

		if(!ReadFeatures(test_data, features)) 
			break;

		auto y_pred = clf.predict(features);
		
		if(y_true == y_pred) ++right_answer;
	}

     return right_answer / all_answer;
}