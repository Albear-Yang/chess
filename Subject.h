#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "observer.h"

class Observer;

class Subject {
  std::vector<Observer*> observers;

 public:
  void attach(Observer *o);
  void detach(Observer *o);
  void notifyObservers() const;
  virtual ~Subject()=0;
};

#endif
