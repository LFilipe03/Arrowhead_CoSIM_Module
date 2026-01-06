// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from services_registry_interfaces:srv/RegistrationInterface.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "services_registry_interfaces/srv/detail/registration_interface__struct.h"
#include "services_registry_interfaces/srv/detail/registration_interface__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool services_registry_interfaces__srv__registration_interface__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[87];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("services_registry_interfaces.srv._registration_interface.RegistrationInterface_Request", full_classname_dest, 86) == 0);
  }
  services_registry_interfaces__srv__RegistrationInterface_Request * ros_message = _ros_message;
  {  // registration_data_json
    PyObject * field = PyObject_GetAttrString(_pymsg, "registration_data_json");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->registration_data_json, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // service_id_with_update
    PyObject * field = PyObject_GetAttrString(_pymsg, "service_id_with_update");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->service_id_with_update = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // method
    PyObject * field = PyObject_GetAttrString(_pymsg, "method");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->method, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * services_registry_interfaces__srv__registration_interface__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RegistrationInterface_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("services_registry_interfaces.srv._registration_interface");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RegistrationInterface_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  services_registry_interfaces__srv__RegistrationInterface_Request * ros_message = (services_registry_interfaces__srv__RegistrationInterface_Request *)raw_ros_message;
  {  // registration_data_json
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->registration_data_json.data,
      strlen(ros_message->registration_data_json.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "registration_data_json", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // service_id_with_update
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->service_id_with_update);
    {
      int rc = PyObject_SetAttrString(_pymessage, "service_id_with_update", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // method
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->method.data,
      strlen(ros_message->method.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "method", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "services_registry_interfaces/srv/detail/registration_interface__struct.h"
// already included above
// #include "services_registry_interfaces/srv/detail/registration_interface__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool services_registry_interfaces__srv__registration_interface__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[88];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("services_registry_interfaces.srv._registration_interface.RegistrationInterface_Response", full_classname_dest, 87) == 0);
  }
  services_registry_interfaces__srv__RegistrationInterface_Response * ros_message = _ros_message;
  {  // value_returned
    PyObject * field = PyObject_GetAttrString(_pymsg, "value_returned");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->value_returned = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * services_registry_interfaces__srv__registration_interface__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RegistrationInterface_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("services_registry_interfaces.srv._registration_interface");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RegistrationInterface_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  services_registry_interfaces__srv__RegistrationInterface_Response * ros_message = (services_registry_interfaces__srv__RegistrationInterface_Response *)raw_ros_message;
  {  // value_returned
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->value_returned);
    {
      int rc = PyObject_SetAttrString(_pymessage, "value_returned", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
