/**
 *   @brief         Get tensorflow library accuracy
 * 
 *   @param[in]     model - directory with model
 *   @param[in]     test_file
 *   @return        accuracy 0...1
 */ 
float GetTensorAccuracy(const char* model, const char* test_file);