ParameterSerializer
===================

[![Build Status](https://travis-ci.org/TubeTK/TubeTK-ParameterSerializer.png?branch=master)](https://travis-ci.org/TubeTK/TubeTK-ParameterSerializer)

Serialization is an important technique when exploring an analysis parameter
solution space and performing reproducible research.

This is a set of classes to perform [serialization](http://en.wikipedia.org/wiki/Serialization)
and deserialization of the parameters of [ITK](http://itk.org) classes, i.e.,
classes that inherit from ```itk::LightObject```. Serialization does not require
code instrumentation of the target classes.  The parameters of the target class
are serialized with an archiver; the only currently implemented archiver writes
and reads [JSON](http://www.json.org) files with the [JsonCpp](http://jsoncpp.sourceforge.net)
library.

The project is currently used by [TubeTK](http://tubetk.org) and the
[SlicerExecutionModel](https://github.com/Slicer/SlicerExecutionModel).

The development of this project is supported by TubeTK.
