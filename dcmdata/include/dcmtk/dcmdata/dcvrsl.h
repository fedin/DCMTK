/*
 *
 *  Copyright (C) 1994-2006, OFFIS
 *
 *  This software and supporting documentation were developed by
 *
 *    Kuratorium OFFIS e.V.
 *    Healthcare Information and Communication Systems
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *  THIS SOFTWARE IS MADE AVAILABLE,  AS IS,  AND OFFIS MAKES NO  WARRANTY
 *  REGARDING  THE  SOFTWARE,  ITS  PERFORMANCE,  ITS  MERCHANTABILITY  OR
 *  FITNESS FOR ANY PARTICULAR USE, FREEDOM FROM ANY COMPUTER DISEASES  OR
 *  ITS CONFORMITY TO ANY SPECIFICATION. THE ENTIRE RISK AS TO QUALITY AND
 *  PERFORMANCE OF THE SOFTWARE IS WITH THE USER.
 *
 *  Module:  dcmdata
 *
 *  Author:  Gerd Ehlers, Andreas Barth
 *
 *  Purpose: Interface of class DcmSignedLong
 *
 *  Last Update:      $Author: uli $
 *  Update Date:      $Date: 2009-11-04 09:58:07 $
 *  Source File:      $Source: /export/gitmirror/dcmtk-git/../dcmtk-cvs/dcmtk/dcmdata/include/dcmtk/dcmdata/dcvrsl.h,v $
 *  CVS/RCS Revision: $Revision: 1.24 $
 *  Status:           $State: Exp $
 *
 *  CVS/RCS Log at end of file
 *
 */


#ifndef DCVRSL_H
#define DCVRSL_H

#include "dcmtk/config/osconfig.h"    /* make sure OS specific configuration is included first */

#include "dcmtk/dcmdata/dcelem.h"


/** a class representing the DICOM value representation 'Signed Long' (SL)
 */
class DcmSignedLong
  : public DcmElement
{

 public:

    /** constructor.
     *  Create new element from given tag and length.
     *  @param tag DICOM tag for the new element
     *  @param len value length for the new element
     */
    DcmSignedLong(const DcmTag &tag,
                  const Uint32 len = 0);

    /** copy constructor
     *  @param old element to be copied
     */
    DcmSignedLong(const DcmSignedLong &old);

    /** destructor
     */
    virtual ~DcmSignedLong();

    /** assignment operator
     *  @param obj element to be assigned/copied
     *  @return reference to this object
     */
    DcmSignedLong &operator=(const DcmSignedLong &obj);

    /** clone method
     *  @return deep copy of this object
     */
    virtual DcmObject *clone() const
    {
      return new DcmSignedLong(*this);
    }

    /** Virtual object copying. This method can be used for DcmObject
     *  and derived classes to get a deep copy of an object. Internally
     *  the assignment operator is called if the given DcmObject parameter
     *  is of the same type as "this" object instance. If not, an error
     *  is returned. This function permits copying an object by value
     *  in a virtual way which therefore is different to just calling the
     *  assignment operator of DcmElement which could result in slicing
     *  the object.
     *  @param rhs - [in] The instance to copy from. Has to be of the same
     *                class type as "this" object
     *  @return EC_Normal if copying was successful, error otherwise
     */
    virtual OFCondition copyFrom(const DcmObject& rhs);

    /** get element type identifier
     *  @return type identifier of this class (EVR_SL)
     */
    virtual DcmEVR ident() const;

    /** get value multiplicity
     *  @return number of currently stored values
     */
    virtual unsigned long getVM();

    /** print element to a stream.
     *  The output format of the value is a backslash separated sequence of numbers.
     *  @param out output stream
     *  @param flags optional flag used to customize the output (see DCMTypes::PF_xxx)
     *  @param level current level of nested items. Used for indentation.
     *  @param pixelFileName not used
     *  @param pixelCounter not used
     */
    virtual void print(STD_NAMESPACE ostream&out,
                       const size_t flags = 0,
                       const int level = 0,
                       const char *pixelFileName = NULL,
                       size_t *pixelCounter = NULL);

    /** get particular integer value
     *  @param sintVal reference to result variable (cleared in case of error)
     *  @param pos index of the value to be retrieved (0..vm-1)
     *  @return status status, EC_Normal if successful, an error code otherwise
     */
    virtual OFCondition getSint32(Sint32 &sintVal,
                                  const unsigned long pos = 0);

    /** get reference to stored integer data.
     *  The number of entries can be determined by "getVM()".
     *  @param sintVals reference to result variable
     *  @return status, EC_Normal if successful, an error code otherwise
     */
    virtual OFCondition getSint32Array(Sint32 *&sintVals);

    /** get particular value as a character string
     *  @param stringVal variable in which the result value is stored
     *  @param pos index of the value in case of multi-valued elements (0..vm-1)
     *  @param normalize not used
     *  @return status, EC_Normal if successful, an error code otherwise
     */
    virtual OFCondition getOFString(OFString &stringVal,
                                    const unsigned long pos,
                                    OFBool normalize = OFTrue);

    /** set particular element value to given integer
     *  @param sintVal signed integer value to be set
     *  @param pos index of the value to be set (0 = first position)
     *  @return status, EC_Normal if successful, an error code otherwise
     */
    virtual OFCondition putSint32(const Sint32 sintVal,
                                  const unsigned long pos = 0);

    /** set element value to given integer array data
     *  @param sintVals signed integer data to be set
     *  @param numSints number of integer values to be set
     *  @return status, EC_Normal if successful, an error code otherwise
     */
    virtual OFCondition putSint32Array(const Sint32 *sintVals,
                                       const unsigned long numSints);

    /** set element value from the given character string.
     *  The input string is expected to be a backslash separated sequence of
     *  numeric characters, e.g. "-333\-22\-1\0\1\22\333".
     *  @param stringVal input character string
     *  @return status, EC_Normal if successful, an error code otherwise
     */
    virtual OFCondition putString(const char *stringVal);

    /** check the currently stored element value
     *  @param autocorrect correct value length if OFTrue
     *  @return status, EC_Normal if value length is correct, an error code otherwise
     */
    virtual OFCondition verify(const OFBool autocorrect = OFFalse);
};


#endif // DCVRSL_H


/*
** CVS/RCS Log:
** $Log: dcvrsl.h,v $
** Revision 1.24  2009-11-04 09:58:07  uli
** Switched to logging mechanism provided by the "new" oflog module
**
** Revision 1.23  2008-07-17 11:19:49  onken
** Updated copyFrom() documentation.
**
** Revision 1.22  2008-07-17 10:30:23  onken
** Implemented copyFrom() method for complete DcmObject class hierarchy, which
** permits setting an instance's value from an existing object. Implemented
** assignment operator where necessary.
**
** Revision 1.21  2006-08-15 15:49:56  meichel
** Updated all code in module dcmdata to correctly compile when
**   all standard C++ classes remain in namespace std.
**
** Revision 1.20  2005/12/08 16:29:08  meichel
** Changed include path schema for all DCMTK header files
**
** Revision 1.19  2004/07/01 12:28:25  meichel
** Introduced virtual clone method for DcmObject and derived classes.
**
** Revision 1.18  2003/06/12 13:29:06  joergr
** Fixed inconsistent API documentation reported by Doxygen.
**
** Revision 1.17  2002/12/06 12:49:18  joergr
** Enhanced "print()" function by re-working the implementation and replacing
** the boolean "showFullData" parameter by a more general integer flag.
** Added doc++ documentation.
** Made source code formatting more consistent with other modules/files.
**
** Revision 1.16  2002/04/25 09:57:08  joergr
** Added getOFString() implementation.
**
** Revision 1.15  2001/09/25 17:19:34  meichel
** Adapted dcmdata to class OFCondition
**
** Revision 1.14  2001/06/01 15:48:52  meichel
** Updated copyright header
**
** Revision 1.13  2000/04/14 15:31:35  meichel
** Removed default value from output stream passed to print() method.
**   Required for use in multi-thread environments.
**
** Revision 1.12  2000/03/08 16:26:25  meichel
** Updated copyright header.
**
** Revision 1.11  2000/03/03 14:05:27  meichel
** Implemented library support for redirecting error messages into memory
**   instead of printing them to stdout/stderr for GUI applications.
**
** Revision 1.10  2000/02/10 10:50:55  joergr
** Added new feature to dcmdump (enhanced print method of dcmdata): write
** pixel data/item value fields to raw files.
**
** Revision 1.9  1999/03/31 09:25:06  meichel
** Updated copyright header in module dcmdata
**
** Revision 1.8  1998/11/12 16:47:54  meichel
** Implemented operator= for all classes derived from DcmObject.
**
** Revision 1.7  1997/07/21 08:25:15  andreas
** - Replace all boolean types (BOOLEAN, CTNBOOLEAN, DICOM_BOOL, BOOL)
**   with one unique boolean type OFBool.
**
** Revision 1.6  1997/04/18 08:13:31  andreas
** - The put/get-methods for all VRs did not conform to the C++-Standard
**   draft. Some Compilers (e.g. SUN-C++ Compiler, Metroworks
**   CodeWarrier, etc.) create many warnings concerning the hiding of
**   overloaded get methods in all derived classes of DcmElement.
**   So the interface of all value representation classes in the
**   library are changed rapidly, e.g.
**   OFCondition get(Uint16 & value, const unsigned long pos);
**   becomes
**   OFCondition getUint16(Uint16 & value, const unsigned long pos);
**   All (retired) "returntype get(...)" methods are deleted.
**   For more information see dcmdata/include/dcelem.h
**
** Revision 1.5  1996/08/05 08:45:35  andreas
** new print routine with additional parameters:
**         - print into files
**         - fix output length for elements
** corrected error in search routine with parameter ESM_fromStackTop
**
** Revision 1.4  1996/01/29 13:38:17  andreas
** - new put method for every VR to put value as a string
** - better and unique print methods
**
** Revision 1.3  1996/01/05 13:23:09  andreas
** - changed to support new streaming facilities
** - more cleanups
** - merged read / write methods for block and file transfer
**
*/
