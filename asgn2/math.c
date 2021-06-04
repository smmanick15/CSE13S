#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

char *validentries = "sctea"; // List valid getopt options

double Sin(double x); // Declare functions to be referenced in int main()
double Cos(double x);
double Tan(double x);
double Exp(double x);

int main(int argc, char **argv) {

  int z = 0;            // character for getopt()
  bool sinfunc = false; // Declare boolean variables for function calls
  bool cosfunc = false;
  bool tanfunc = false;
  bool expfunc = false;
  bool allfunc = false;

  if (argc == 1) { // Print menu if no arguments are provided in getopt()
    printf("-s:runs sin tests\n");
    printf("-c:runs cos tests\n");
    printf("-t:runs tan tests\n");
    printf("-e:runs exp tests\n");
    printf("-a:runs all tests\n");
  }

  if (argc == 2) {
    while ((z = getopt(argc, argv, validentries)) != -1) {
      if (z == 's') { // If user entered -s: make sin boolean true
        sinfunc = true;
      }

      if (z == 'c') { // If user entered -c: make cos boolean true
        cosfunc = true;
      }

      if (z == 't') { // If user entered -t: make tan boolean true
        tanfunc = true;
      }

      if (z == 'e') { // If user entered -e: make exp boolean true
        expfunc = true;
      }

      if (z == 'a') { // If user entered -a: make all boolean true
        allfunc = true;
      }
    }
  }

  if (sinfunc) {
    printf("x\tSin\t\tLibrary\t\tDifference\n"); // Print header
    printf("-\t---\t\t-------\t\t----------\n"); // for Sin function

    // Loop to print Sin function with range [-2pi, 2pi] (steps of pi/16)
    for (double i = (-2 * M_PI); i <= ((2 * M_PI) + (M_PI / 16));
         i += ((M_PI) / 16)) {
      printf("%6.4lf\t%10.8lf\t%10.8lf\t%12.10lf\n", i, Sin(i), sin(i),
             (Sin(i) - sin(i)));
    }
  }

  if (cosfunc) {
    printf("x\tCos\t\tLibrary\t\tDifference\n"); // Print header
    printf("-\t---\t\t-------\t\t----------\n"); // for Cos function

    // Loop to print Cos function with range [-2pi, 2pi] (steps of pi/16)
    for (double i = (-2 * M_PI); i <= ((2 * M_PI) + (M_PI / 16));
         i += ((M_PI) / 16)) {
      printf("%6.4lf\t%10.8lf\t%10.8lf\t%12.10lf\n", i, Cos(i), cos(i),
             (Cos(i) - cos(i)));
    }
  }

  if (tanfunc) {
    printf("x\tTan\t\tLibrary\t\tDifference\n"); // Print header
    printf("-\t---\t\t-------\t\t----------\n"); // for Tan function

    // Loop to print Tan function with range [-pi/3, pi/3) with steps of pi/16
    for (double i = (((-1) * M_PI) / 3); i <= (((M_PI) / 3));
         i += ((M_PI) / 16)) {

      printf("%6.4lf\t%10.8lf\t%10.8lf\t%12.10lf\n", i, Tan(i), tan(i),
             (Tan(i) - tan(i)));
    }
  }

  if (expfunc) {

    printf("x\tExp\t\tLibrary\t\tDifference\n"); // Print header
    printf("-\t---\t\t-------\t\t----------\n"); // for Exp function

    // Loop to print e^x function with range [0, 9] (steps of 0.1)
    for (double start = 0; start < 9; start += 0.1) {
      printf("%6.4lf\t%10.8lf\t%10.8lf\t%12.10lf\n", start, Exp(start),
             exp(start), (Exp(start) - exp(start)));
    }
  }

  if (allfunc) {
    printf("x\tSin\t\tLibrary\t\tDifference\n"); // Print header
    printf("-\t---\t\t-------\t\t----------\n"); // for Sin function

    // Loop to print Sin function with range [-2pi, 2pi] (steps of pi/16)
    for (double i = (-2 * M_PI); i <= ((2 * M_PI) + (M_PI / 16));
         i += ((M_PI) / 16)) {
      printf("%6.4lf\t%10.8lf\t%10.8lf\t%12.10lf\n", i, Sin(i), sin(i),
             (Sin(i) - sin(i)));
    }

    printf("x\tCos\t\tLibrary\t\tDifference\n"); // Print header
    printf("-\t---\t\t-------\t\t----------\n"); // for Cos function

    // Loop to print Cos function with range [-2pi, 2pi] (steps of pi/16)
    for (double i = (-2 * M_PI); i <= ((2 * M_PI) + (M_PI / 16));
         i += ((M_PI) / 16)) {
      printf("%6.4lf\t%10.8lf\t%10.8lf\t%12.10lf\n", i, Cos(i), cos(i),
             (Cos(i) - cos(i)));
    }

    printf("x\tTan\t\tLibrary\t\tDifference\n"); // Print header
    printf("-\t---\t\t-------\t\t----------\n"); // for Tan function

    // Loop to print Tan function with range [-pi/3, pi/3) with steps of pi/16
    for (double i = (((-1) * M_PI) / 3); i <= (((M_PI) / 3));
         i += ((M_PI) / 16)) {

      printf("%6.4lf\t%10.8lf\t%10.8lf\t%12.10lf\n", i, Tan(i), tan(i),
             (Tan(i) - tan(i)));
    }

    printf("x\tExp\t\tLibrary\t\tDifference\n"); // Print header
    printf("-\t---\t\t-------\t\t----------\n"); // for Exp function

    // Loop to print e^x function with range [0, 9] (steps of 0.1)
    for (double start = 0; start < 9; start += 0.1) {
      printf("%6.4lf\t%10.8lf\t%10.8lf\t%12.10lf\n", start, Exp(start),
             exp(start), (Exp(start) - exp(start)));
    }
  }
  return 0;
}

double Sin(double x) {
  // Initialize Sin Variables
  double xsquared = x * x;
  double numerator1 = 0;
  double numerator2 = 0;
  double denominator1 = 0;
  double denominator2 = 0;
  double sinvalue = 0;

  // Calculate numerator
  numerator1 = (((52785432 - (479249 * xsquared)) * xsquared) - 1640635920);
  numerator2 = ((numerator1 * xsquared) + 11511339840) * x;

  // Calculate denominator
  denominator1 = (((18361 * xsquared) + 3177720) * xsquared) + 277920720;
  denominator2 = (denominator1 * xsquared) + 11511339840;

  // Calculate sinvalue
  sinvalue = numerator2 / denominator2;

  return sinvalue;
}

double Cos(double x) {
  // Initialize Sin Variables
  double xsquared = x * x;
  double numerator1 = 0;
  double numerator2 = 0;
  double denominator1 = 0;
  double denominator2 = 0;
  double cosvalue = 0;

  // Calculate numerator
  numerator1 = (((1075032 - (14615 * xsquared)) * xsquared) - 18471600);
  numerator2 = (numerator1 * xsquared) + 39251520;

  // Calculate denominator
  denominator1 = ((((127 * xsquared) + 16632) * xsquared) + 1154160);
  denominator2 = (denominator1 * xsquared) + 39251520;

  // Calculate sinvalue
  cosvalue = numerator2 / denominator2;

  return cosvalue;
}

double Tan(double x) {
  // Initialize Sin Variables
  double xsquared = x * x;
  double xfour = xsquared * xsquared;
  double xsix = xfour * xsquared;
  double xeight = xsix * xsquared;
  double numerator1 = 0;
  double numerator2 = 0;
  double denominator1 = 0;
  double denominator2 = 0;
  double tanvalue = 0;

  // Calculate numerator
  numerator1 = (xeight - (990 * xsix) + (135135 * xfour));
  numerator2 = ((numerator1 - (4729725 * xsquared) + 34459425) * x);

  // Calculate denominator
  denominator1 = (xeight - (308 * xsix) + (21021 * xfour));
  denominator2 = ((denominator1 - (360360 * xsquared) + 765765) * 45);

  // Calculate sinvalue
  tanvalue = numerator2 / denominator2;

  return tanvalue;
}

double Exp(double x) {
  // Calculate 1+x
  double sum = 1 + x;

  // Initialize Loop Variables
  int n = 1;
  double denominator = n * n;
  double currentsum = 0;
  double epsilon = 10e-9;

  do {
    // increment n
    ++n;
    double numerator = x;

    // calculate numerator (FOR LOOP):
    for (int i = 0; i < n - 1; ++i) {
      double mult = x;
      numerator = numerator * mult;
    }

    // calculate denominator:
    denominator = denominator * n;

    // calculate current sum:
    currentsum = numerator / denominator;
    sum = sum + currentsum;
  } while (currentsum > epsilon);

  return sum;
}
