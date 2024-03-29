/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkUnsignedLongArray.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkUnsignedLongArray - dynamic, self-adjusting array of unsigned long
// .SECTION Description
// vtkUnsignedLongArray is an array of values of type unsigned long.
// It provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.

#ifndef __vtkUnsignedLongArray_h
#define __vtkUnsignedLongArray_h

// Tell the template header how to give our superclass a DLL interface.
#if !defined(__vtkUnsignedLongArray_cxx)
# define VTK_DATA_ARRAY_TEMPLATE_TYPE unsigned long
#endif

#include "vtkDataArray.h"
#include "vtkDataArrayTemplate.h" // Real Superclass

// Fake the superclass for the wrappers.
#define vtkDataArray vtkDataArrayTemplate<unsigned long>
class VTK_COMMON_EXPORT vtkUnsignedLongArray : public vtkDataArray
#undef vtkDataArray
{
public:
  static vtkUnsignedLongArray* New();
  vtkTypeMacro(vtkUnsignedLongArray,vtkDataArray);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Get the data type.
  int GetDataType()
    { return VTK_UNSIGNED_LONG; }

  // Description:
  // Copy the tuple value into a user-provided array.
  void GetTupleValue(vtkIdType i, unsigned long* tuple)
    { this->RealSuperclass::GetTupleValue(i, tuple); }

  // Description:
  // Set the tuple value at the ith location in the array.
  void SetTupleValue(vtkIdType i, const unsigned long* tuple)
    { this->RealSuperclass::SetTupleValue(i, tuple); }

  // Description:
  // Insert (memory allocation performed) the tuple into the ith location
  // in the array.
  void InsertTupleValue(vtkIdType i, const unsigned long* tuple)
    { this->RealSuperclass::InsertTupleValue(i, tuple); }

  // Description:
  // Insert (memory allocation performed) the tuple onto the end of the array.
  vtkIdType InsertNextTupleValue(const unsigned long* tuple)
    { return this->RealSuperclass::InsertNextTupleValue(tuple); }

  // Description:
  // Get the data at a particular index.
  unsigned long GetValue(vtkIdType id)
    { return this->RealSuperclass::GetValue(id); }

  // Description:
  // Set the data at a particular index. Does not do range checking. Make sure
  // you use the method SetNumberOfValues() before inserting data.
  void SetValue(vtkIdType id, unsigned long value)
    { this->RealSuperclass::SetValue(id, value); }

  // Description:
  // Specify the number of values for this object to hold. Does an
  // allocation as well as setting the MaxId ivar. Used in conjunction with
  // SetValue() method for fast insertion.
  void SetNumberOfValues(vtkIdType number)
    { this->RealSuperclass::SetNumberOfValues(number); }

  // Description:
  // Insert data at a specified position in the array.
  void InsertValue(vtkIdType id, unsigned long f)
    { this->RealSuperclass::InsertValue(id, f); }

  // Description:
  // Insert data at the end of the array. Return its location in the array.
  vtkIdType InsertNextValue(unsigned long f)
    { return this->RealSuperclass::InsertNextValue(f); }

  // Description:
  // Get the address of a particular data index. Make sure data is allocated
  // for the number of items requested. Set MaxId according to the number of
  // data values requested.
  unsigned long* WritePointer(vtkIdType id, vtkIdType number)
    { return this->RealSuperclass::WritePointer(id, number); }

  // Description:
  // Get the address of a particular data index. Performs no checks
  // to verify that the memory has been allocated etc.
  unsigned long* GetPointer(vtkIdType id)
    { return this->RealSuperclass::GetPointer(id); }

  // Description:
  // This method lets the user specify data to be held by the array.  The
  // array argument is a pointer to the data.  size is the size of
  // the array supplied by the user.  Set save to 1 to keep the class
  // from deleting the array when it cleans up or reallocates memory.
  // The class uses the actual array provided; it does not copy the data
  // from the suppled array. 
  void SetArray(unsigned long* array, vtkIdType size, int save)
    { this->RealSuperclass::SetArray(array, size, save); }
  void SetArray(unsigned long* array, vtkIdType size, int save, int deleteMethod)
    { this->RealSuperclass::SetArray(array, size, save, deleteMethod); }

protected:
  vtkUnsignedLongArray(vtkIdType numComp=1);
  ~vtkUnsignedLongArray();

private:
  //BTX
  typedef vtkDataArrayTemplate<unsigned long> RealSuperclass;
  //ETX
  vtkUnsignedLongArray(const vtkUnsignedLongArray&);  // Not implemented.
  void operator=(const vtkUnsignedLongArray&);  // Not implemented.
};

#endif
