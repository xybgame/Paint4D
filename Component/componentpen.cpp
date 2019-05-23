#include "componentpen.h"

ComponentPen::ComponentPen()
{
    id=QUuid::createUuid().toString();
    type="ComponentPen";
}

void ComponentPen::xyb_MouseMove(XYBEvent &e)
{

}
