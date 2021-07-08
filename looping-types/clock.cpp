// Clock class by ENDeveloper
// Creates a controlled atificial overflow.
//
//
//
//
//
//
// max_val > min_val
//
// If you are not sure whether you are adding a positive or negative value:
// Use clock.subtract(-1 * value);
// This function is slower but works on all negative and positibe values.
// 
// If you are not sure whether you are multiplying a positive or negative value:
// Use clock.smultiply(value);
// This function is slower aswell but works on all negative and positibe values.
//
// If somewhere in the program you set the clock value manually by: clock.value = 26;
// Use clock.subtract(0);
// This will make sure your value is legal.
//
// -------------------------------------------------------------------------------- //



class Clock {
    public:
        double value;
        double max;
        double min;
        void add(double val);
        void subtract(double val);
        void multiply(double val);
        void smultiply(double val);
        Clock(double initial_val, double max_val, double min_val);
    private:
        double max_min_difference;
};

void Clock::add(double val) {
    value = std::fmod(value + val, max_min_difference);
}
void Clock::subtract(double val) {
    value = value - val < min ? max + std::fmod(value - val, max_min_difference) : value - val;
}
void Clock::multiply(double val) {
    value = std::fmod(value * val, max_min_difference);
}
void Clock::smultiply(double val){
    subtract(-1 * value * val);
}
Clock::Clock(double initial_val, double max_val, double min_val) {
    if(min_val < max_val){
        throw "PARAMETER ERROR:\nThe chosen minimum value was larger or equal to the chosen maximum value while creating an Instance of \"Clock\".\nFix this issue by making the minimum value smaller than the maximum value.";
    }
    value = initial_val;
    max = max_val;
    min = min_val;
    max_min_difference = max - min;
}

// End of file
// -------------------------------------------------------------------------------- //
//
