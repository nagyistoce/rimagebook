/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkSimpleElevationFilter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkSimpleElevationFilter - generate scalars along a specified direction
// .SECTION Description
// vtkSimpleElevationFilter is a filter to generate scalar values from a
// dataset.  The scalar values are generated by dotting a user-specified
// vector against a vector defined from the input dataset points to the
// origin. 
// .SECTION See Also
// vtkElevationFilter

#ifndef __vtkSimpleElevationFilter_h
#define __vtkSimpleElevationFilter_h

#include "vtkDataSetAlgorithm.h"

class VTK_GRAPHICS_EXPORT vtkSimpleElevationFilter : public vtkDataSetAlgorithm 
{
public:
  vtkTypeMacro(vtkSimpleElevationFilter,vtkDataSetAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Construct object with Vector=(0,0,1);
  static vtkSimpleElevationFilter *New();

  // Description:
  // Define one end of the line (small scalar values).
  vtkSetVector3Macro(Vector,double);
  vtkGetVectorMacro(Vector,double,3);

protected:
  vtkSimpleElevationFilter();
  ~vtkSimpleElevationFilter() {};

  int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);
  double Vector[3];
private:
  vtkSimpleElevationFilter(const vtkSimpleElevationFilter&);  // Not implemented.
  void operator=(const vtkSimpleElevationFilter&);  // Not implemented.
};

#endif


