ParameterSerializer
===================

Serialization is an important technique when exploring an analysis parameter
solution space and performing reproducible research.

This is a set of classes to perform serialization_ and deserialization of the
parameters of ITK_ classes, i.e. classes that inherit from `itk::LightObject`_.
Serialization does not require code instrumentation of the target classes.  The
parameters of the target class are serialized with an archiver; the only
currently implemented archiver writes and reads JSON_ files with the JsonCpp_
library.

The project is currently used by TubeTK_ and the SlicerExecutionModel_.

The development of this project is supported by TubeTK_.

.. _serialization: http://en.wikipedia.org/wiki/Serialization
.. _ITK: http://itk.org/
.. _`itk::LightObject`: http://www.itk.org/Doxygen/html/classitk_1_1LightObject.html
.. _TubeTK: http://tubetk.org/
.. _JSON: http://www.json.org/
.. _JsonCpp: https://github.com/TubeTK/jsoncpp-cmake
.. _SlicerExecutionModel: https://github.com/Slicer/SlicerExecutionModel
