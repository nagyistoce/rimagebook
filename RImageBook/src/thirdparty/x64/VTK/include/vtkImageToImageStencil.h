/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkImageToImageStencil.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkImageToImageStencil - clip an image with a mask image
// .SECTION Description
// vtkImageToImageStencil will convert a vtkImageData into an stencil
// that can be used with vtkImageStecil or other vtk classes that apply
// a stencil to an image.
// .SECTION see also
// vtkImageStencil vtkImplicitFunctionToImageStencil vtkPolyDataToImageStencil

#ifndef __vtkImageToImageStencil_h
#define __vtkImageToImageStencil_h


#include "vtkImageStencilSource.h"

class vtkImageData;

class VTK_IMAGING_EXPORT vtkImageToImageStencil : public vtkImageStencilSource
{
public:
  static vtkImageToImageStencil *New();
  vtkTypeMacro(vtkImageToImageStencil, vtkImageStencilSource);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Specify the image data to convert into a stencil.
  void SetInput(vtkImageData *input);
  vtkImageData *GetInput();

  // Description:
  // The values greater than or equal to the value match.
  void ThresholdByUpper(double thresh);
  
  // Description:
  // The values less than or equal to the value match.
  void ThresholdByLower(double thresh);
  
  // Description:
  // The values in a range (inclusive) match
  void ThresholdBetween(double lower, double upper);
  
  // Description:
  // Get the Upper and Lower thresholds.
  vtkSetMacro(UpperThreshold, double);
  vtkGetMacro(UpperThreshold, double);
  vtkSetMacro(LowerThreshold, double);
  vtkGetMacro(LowerThreshold, double);

protected:
  vtkImageToImageStencil();
  ~vtkImageToImageStencil();

  virtual int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);
  virtual int RequestInformation(vtkInformation *, vtkInformationVector **, vtkInformationVector *);
  virtual int RequestUpdateExtent(vtkInformation *, vtkInformationVector **, vtkInformationVector *);
  virtual int FillInputPortInformation(int, vtkInformation*);
  
  double UpperThreshold;
  double LowerThreshold;
  double Threshold;
private:
  vtkImageToImageStencil(const vtkImageToImageStencil&);  // Not implemented.
  void operator=(const vtkImageToImageStencil&);  // Not implemented.
};

#endif
