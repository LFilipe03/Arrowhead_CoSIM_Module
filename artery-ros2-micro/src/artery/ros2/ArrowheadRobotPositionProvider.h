#ifndef ARTERY_ARROWHEADROBOTPOSITIONPROVIDER_H_6GFEWEFCFE
#define ARTERY_ARROWHEADROBOTPOSITIONPROVIDER_H_6GFEWEFCFE

#include "artery/networking/PositionFixObject.h"
#include "artery/networking/PositionProvider.h"
#include "artery/networking/Runtime.h"
#include <omnetpp/clistener.h>
#include <omnetpp/csimplemodule.h>
#include <vanetza/common/position_provider.hpp>

namespace artery
{

class ArrowheadRobotInetMobility;

class ArrowheadRobotPositionProvider :
    public omnetpp::cSimpleModule, public omnetpp::cListener,
    public vanetza::PositionProvider, public artery::PositionProvider
{
public:
    void initialize(int stage) override;
    int numInitStages() const override;
    void receiveSignal(omnetpp::cComponent*, omnetpp::simsignal_t, omnetpp::cObject*, omnetpp::cObject*) override;
    const vanetza::PositionFix& position_fix() override { return mPositionFix; }

    // PositionProvider
    Position getCartesianPosition() const override;
    GeoPosition getGeodeticPosition() const override;

private:
    void updatePositionFix();

    PositionFixObject mPositionFix;
    Runtime* mRuntime = nullptr;
    ArrowheadRobotInetMobility* mMobility = nullptr;
};

} // namespace artery

#endif /* ARTERY_ARROWHEADROBOTPOSITIONPROVIDER_H_6GFEWEFCFE */
