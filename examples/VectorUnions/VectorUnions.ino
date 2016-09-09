#include "Arduino.h"
#include "Streaming.h"
#include "ConstantVariable.h"
#include "Vector.h"


const int BAUDRATE = 9600;

union MemberType
{
  const long l;
  ConstantString * const sp;
};

enum{ODD_SUBSET_LENGTH=5};
const MemberType odd_subset[ODD_SUBSET_LENGTH] = {1,3,5,7,9};
Vector<const MemberType> odd_subset_vector;

enum{MODE_SUBSET_LENGTH=3};
CONSTANT_STRING(mode_rising,"RISING");
CONSTANT_STRING(mode_falling,"FALLING");
CONSTANT_STRING(mode_change,"CHANGE");
const MemberType mode_ptr_subset[MODE_SUBSET_LENGTH] =
  {
    &mode_rising,
    &mode_falling,
    &mode_change,
  };
Vector<const MemberType> mode_ptr_subset_vector;

void setup()
{
  Serial.begin(BAUDRATE);
  delay(1000);

  odd_subset_vector.setStorage(odd_subset,ODD_SUBSET_LENGTH);
  mode_ptr_subset_vector.setStorage(mode_ptr_subset,MODE_SUBSET_LENGTH);
}


void loop()
{
  Serial << "[";
  for (int i=0; i<odd_subset_vector.size(); i++)
  {
    if (i != 0)
    {
      Serial << ",";
    }
    Serial << odd_subset_vector[i].l;
  }
  Serial << "]" << endl;

  Serial << "[";
  for (int i=0; i<mode_ptr_subset_vector.size(); i++)
  {
    if (i != 0)
    {
      Serial << ",";
    }
    Serial << *mode_ptr_subset_vector[i].sp;
  }
  Serial << "]" << endl;

  Serial << endl;

  delay(1000);
}