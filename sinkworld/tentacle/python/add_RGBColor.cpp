#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <string>
#include <iostream>
#include <assert.h>
#include "base.h"
#include "lexers.h"

// Using =======================================================================
using namespace boost::python;

typedef void *HWND;
typedef void *HINSTANCE;

#include "PhysicalLayout.h"

#include "RegisteredLexers.h"
#include "RGBColor.h"
#include "IDecoration.h"
#include "BaseDecoration.h"
#include "RegisteredDecorations.h"
#include "Style.h"
#include "StyleModification.h"
#include "StyleSet.h"
#include "StyleSetCollection.h"
#include "FontDescription.h"
#include "Surface.h"
#include "ChangeLayer.h"
#include "ChangeFinder.h"
#include "StyleLayer.h"
#include "SubstanceLayer.h"
#include "PositionCache.h"
#include "LinePositionCache.h"
#include "ChangePositionsCache.h"
#include "Document.h"

#include "PhasedPaint.h"
#include "TextView.h"
#include "RangeSelection.h"

#include "DecorationBox.h"
#include "DecorationButton.h"
#include "DecorationCaret.h"
#include "DecorationGraduatedBox.h"
#include "DecorationStrikeOut.h"
#include "DecorationRoundedBox.h"
#include "DecorationUnderLine.h"

#include "TentacleControl.h"

#include "SWWrappers.h"

void add_RGBColor() {
    class_< RGBColor, boost::noncopyable >("RGBColor", init<  >())
        .def(init< long int >())
        .def(init< long int, long int, long int >())
        .def_readwrite("co", &RGBColor::co)
        .def("AsBGR", &RGBColor::AsBGR)
        .def("AsRGB", &RGBColor::AsRGB)
        .def("NotEqual", &RGBColor::NotEqual)
        .def("GetRed", &RGBColor::GetRed)
        .def("GetGreen", &RGBColor::GetGreen)
        .def("GetBlue", &RGBColor::GetBlue)
        .def("Merge", &RGBColor::Merge)
    ;

}