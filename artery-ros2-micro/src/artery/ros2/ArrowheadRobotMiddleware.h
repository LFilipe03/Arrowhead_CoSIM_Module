#ifndef ARTERY_ARROWHEADROBOTMIDDLEWARE_H_RNPOR234
#define ARTERY_ARROWHEADROBOTMIDDLEWARE_H_RNPOR234

#include "artery/application/Middleware.h"
#include "artery/application/VehicleDataProvider.h"
#include "artery/application/VehicleKinematics.h"

namespace artery
{

class ArrowheadRobotInetMobility;

class ArrowheadRobotMiddleware : public Middleware
{
public:
    ArrowheadRobotMiddleware();
    void initialize(int stage) override;
    void receiveSignal(omnetpp::cComponent*, omnetpp::simsignal_t, omnetpp::cObject*, omnetpp::cObject*) override;

protected:
    void initializeStationType(const std::string&);
    VehicleKinematics getKinematics(const ArrowheadRobotInetMobility&) const;

private:
    VehicleDataProvider mVehicleDataProvider;
    ArrowheadRobotInetMobility* mMobility = nullptr;
};

} // namespace artery

#endif /* ARTERY_ARROWHEADROBOTMIDDLEWARE_H_RNPOR234 */

