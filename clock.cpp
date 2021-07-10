// Clock class by ENDeveloper
// Creates a controlled atificial overflow.
//
// The clock class is a double which can be increased until they reach their maximum to
// loop back around to the minumum and decreased until they reach the minimum to loop
// to the maximum value. The maximum and minimum are the same number. That means max +
// any positive non zero number will result in looping back around to a number larger
// than the minimum.
//
//
//
//
//
//
// max_val > min_val
//
// new Clock( /* initial value */ , /* maximum value */ , /* minimum value)
//
// assignement operators:
// += , -= , *= , /= , %= , = , ++ , --
// binary operators
// + , - , * , / , %
// reference
// double << clock_name
// double << clock_name.max
// double << clock_name.min
//
// zap operations 
// += , -= , *= , /= , %= , = , zget();
// q operations
// ++ , --
//
// -------------------------------------------------------------------------------- //


class Clock {
    public:
        // max / min
        double max;
        double min;
        // assignement operators
        void operator += (long double val);
        void operator += (Clock& val);
        void operator -= (long double val);
        void operator -= (Clock& val);
        void operator *= (long double val);
        void operator *= (Clock& val);
        void operator /= (long double val);
        void operator /= (Clock& val);
        void operator %= (long double val);
        void operator %= (Clock& val);
        void operator =  (long double val);
        void operator =  (Clock& val);
        void operator ++ ();
        void operator -- ();
        void newboundries (double max, double min);
        // binary operators
        double operator + (double val);
        double operator + (Clock &val);
        double operator - (double val);
        double operator - (Clock &val);
        double operator * (double val);
        double operator * (Clock &val);
        double operator / (double val);
        double operator / (Clock &val);
        double operator % (double val);
        double operator % (Clock& val);
        // reference
        operator double();
        friend std::ostream& operator << (std::ostream& o, const Clock* in_clock);
        friend std::istream& operator >> (std::istream& i, const Clock* in_clock);
        // constructor
        Clock(double max_val, double min_val, double initial_val);
        Clock(double max_val, double min_val);
        // misc
        double zget();
    private:
        long double max_min_difference;
        double value;
        void set();
};
// public
// assignment operators
void Clock::operator += (long double val){value += val;}
void Clock::operator += (Clock& val){value += val.zget();}
void Clock::operator -= (long double val){value -= val;}
void Clock::operator -= (Clock& val){value -= val.zget();}
void Clock::operator *= (long double val){value *= val;}
void Clock::operator *= (Clock& val){value *= val.zget();}
void Clock::operator /= (long double val){value /= val;}
void Clock::operator /= (Clock& val){value /= val.zget();}
void Clock::operator %= (long double val){value = std::fmod(value,val);}
void Clock::operator %= (Clock& val){value = std::fmod(value,val.zget());}
void Clock::operator = (long double val){value = val;}
void Clock::operator = (Clock& val){value = val.zget();}
void Clock::operator ++ (){value++;}
void Clock::operator -- (){value--;}
// binary operators
double Clock::operator + (double val){set(); return value + val;}
double Clock::operator + (Clock &val){set(); return value + val.zget();}
double Clock::operator - (double val){set(); return value - val;}
double Clock::operator - (Clock &val){set(); return value - val.zget();}
double Clock::operator * (double val){set(); return value * val;}
double Clock::operator * (Clock &val){set(); return value * val.zget();}
double Clock::operator / (double val){set(); return value / val;}
double Clock::operator / (Clock &val){set(); return value / val.zget();}
double Clock::operator % (double val){set(); return std::fmod(value,val);}
double Clock::operator % (Clock& val){set(); return std::fmod(value,val.zget());}
// reference
Clock::operator double(){set(); return value;}
double Clock::zget(){return value;};
// private
void Clock::set(){
    long double modulo_val_dif = std::fmod(value - min, max_min_difference);
    value = value < min ? modulo_val_dif + max_min_difference + min : modulo_val_dif + min;
}
// contructor
Clock::Clock(double max_val, double min_val, double initial_val) {
    if(min_val >= max_val){
        throw "PARAMETER ERROR:\nThe chosen minimum value was larger or equal to the chosen maximum value while creating an Instance of \"Clock\".\nFix this issue by making the minimum value smaller than the maximum value.";
    }
    value = initial_val;
    max = max_val;
    min = min_val;
    max_min_difference = max - min;
}
Clock::Clock(double max_val, double min_val) {
    if(min_val >= max_val){
        throw "PARAMETER ERROR:\nThe chosen minimum value was larger or equal to the chosen maximum value while creating an Instance of \"Clock\".\nFix this issue by making the minimum value smaller than the maximum value.";
    }
    value = 0;
    max = max_val;
    min = min_val;
    max_min_difference = max - min;
}
// friend
std::ostream& operator << (std::ostream& o, Clock& in_clock){
    o << (int) in_clock;
    return o;
}
std::istream& operator >> (std::istream& i, Clock& in_clock){
    double input;
    i >> input;
    in_clock = input;
    return i;
}

// End of file
// -------------------------------------------------------------------------------- //
//