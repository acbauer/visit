/*****************************************************************************
*
* Copyright (c) 2000 - 2019, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#ifndef VTK_TIME_SLIDER_ACTOR_H
#define VTK_TIME_SLIDER_ACTOR_H
#include <plotter_exports.h>
#include <vtkActor2D.h>

class vtkCellArray;
class vtkPolyData;
class vtkPolyDataMapper2D;

// ****************************************************************************
// Class: vtkTimeSliderActor
//
// Purpose:
//   This class is a time slider actor that can be added to a VTK renderer.
//
// Notes:
//
// Programmer: Brad Whitlock
// Creation:   Tue Oct 28 11:37:07 PDT 2003
//
// Modifications:
//
// ****************************************************************************

class PLOTTER_API vtkTimeSliderActor : public vtkActor2D
{
public:
  vtkTypeMacro(vtkTimeSliderActor, vtkActor2D);
  void PrintSelf(ostream &os, vtkIndent indent) override;

  // Description:
  // Instantiate a time slider actor.
  static vtkTimeSliderActor *New();

  // Description:
  // Draw the actor as per the vtkProp superclass' API.
  int RenderOverlay(vtkViewport *) override;
  int RenderOpaqueGeometry(vtkViewport *) override;
  int RenderTranslucentPolygonalGeometry(vtkViewport *) override;
  int HasTranslucentPolygonalGeometry() override;

  vtkSetVector4Macro(StartColor, double);
  vtkGetVector4Macro(StartColor, double);

  vtkSetVector4Macro(EndColor, double);
  vtkGetVector4Macro(EndColor, double);

  vtkSetMacro(ParametricTime, double);
  vtkGetMacro(ParametricTime, double);

  vtkSetClampMacro(VerticalDivisions, int, 1, 16);
  vtkGetMacro(VerticalDivisions, int);

  vtkSetClampMacro(DrawEndCaps, int, 0, 1);
  vtkGetMacro(DrawEndCaps, int);

  vtkSetClampMacro(RadialDivisions, int, 5, 100);
  vtkGetMacro(RadialDivisions, int);

  vtkSetClampMacro(Draw3D, int, 0, 1);
  vtkGetMacro(Draw3D, int);

protected:
  vtkTimeSliderActor();
  ~vtkTimeSliderActor();
  void DestroySlider();
  void AddEndCapCells(int, vtkCellArray *);
  void CreateSlider(vtkViewport *viewport);

  double  StartColor[4];
  double  EndColor[4];
  double ParametricTime;

  int    VerticalDivisions;
  int    DrawEndCaps;
  int    RadialDivisions;
  int    Draw3D;

  vtkPolyData         *SliderPolyData;
  vtkActor2D          *SliderActor;
  vtkPolyDataMapper2D *SliderMapper;

private:
  vtkTimeSliderActor(const vtkTimeSliderActor &);
  void operator =(const vtkTimeSliderActor &);
};

#endif
