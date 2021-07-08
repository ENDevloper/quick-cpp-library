
class Clock {
   public:
      double value;
      double max;
      double min;
      void add(double val);
      void sub(double val);
      void mul(double val);
      Clock(double initial_val, double max_val, double min_val);
};

void Clock::add(double val) {
   value = std::fmod(value + val, max - min);
}
void Clock::sub(double val) {
   value = value - val < 0 ?  24 + std::fmod(value - val, max - min) : value - val;
}
void Clock::mul(double val) {
   value = std::fmod(value * val, max - min);
}
Clock::Clock(double initial_val, double max_val, double min_val) {
   value = initial_val;
   max = max_val;
   min = min_val;
}
