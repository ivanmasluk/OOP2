#pragma once

#include "IObserver.h"

class IObservable {
public:
    virtual ~IObservable() = default;
    virtual void subscribe(IObserver* observer) = 0;
    virtual void unsubscribe(IObserver* observer) = 0;
    virtual void notify(const UnitEvent& event) = 0;
};
