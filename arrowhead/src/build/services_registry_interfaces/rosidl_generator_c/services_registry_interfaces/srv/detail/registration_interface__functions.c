// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from services_registry_interfaces:srv/RegistrationInterface.idl
// generated code does not contain a copyright notice
#include "services_registry_interfaces/srv/detail/registration_interface__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Include directives for member types
// Member `registration_data_json`
// Member `method`
#include "rosidl_runtime_c/string_functions.h"

bool
services_registry_interfaces__srv__RegistrationInterface_Request__init(services_registry_interfaces__srv__RegistrationInterface_Request * msg)
{
  if (!msg) {
    return false;
  }
  // registration_data_json
  if (!rosidl_runtime_c__String__init(&msg->registration_data_json)) {
    services_registry_interfaces__srv__RegistrationInterface_Request__fini(msg);
    return false;
  }
  // service_id_with_update
  // method
  if (!rosidl_runtime_c__String__init(&msg->method)) {
    services_registry_interfaces__srv__RegistrationInterface_Request__fini(msg);
    return false;
  }
  return true;
}

void
services_registry_interfaces__srv__RegistrationInterface_Request__fini(services_registry_interfaces__srv__RegistrationInterface_Request * msg)
{
  if (!msg) {
    return;
  }
  // registration_data_json
  rosidl_runtime_c__String__fini(&msg->registration_data_json);
  // service_id_with_update
  // method
  rosidl_runtime_c__String__fini(&msg->method);
}

bool
services_registry_interfaces__srv__RegistrationInterface_Request__are_equal(const services_registry_interfaces__srv__RegistrationInterface_Request * lhs, const services_registry_interfaces__srv__RegistrationInterface_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // registration_data_json
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->registration_data_json), &(rhs->registration_data_json)))
  {
    return false;
  }
  // service_id_with_update
  if (lhs->service_id_with_update != rhs->service_id_with_update) {
    return false;
  }
  // method
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->method), &(rhs->method)))
  {
    return false;
  }
  return true;
}

bool
services_registry_interfaces__srv__RegistrationInterface_Request__copy(
  const services_registry_interfaces__srv__RegistrationInterface_Request * input,
  services_registry_interfaces__srv__RegistrationInterface_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // registration_data_json
  if (!rosidl_runtime_c__String__copy(
      &(input->registration_data_json), &(output->registration_data_json)))
  {
    return false;
  }
  // service_id_with_update
  output->service_id_with_update = input->service_id_with_update;
  // method
  if (!rosidl_runtime_c__String__copy(
      &(input->method), &(output->method)))
  {
    return false;
  }
  return true;
}

services_registry_interfaces__srv__RegistrationInterface_Request *
services_registry_interfaces__srv__RegistrationInterface_Request__create()
{
  services_registry_interfaces__srv__RegistrationInterface_Request * msg = (services_registry_interfaces__srv__RegistrationInterface_Request *)malloc(sizeof(services_registry_interfaces__srv__RegistrationInterface_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(services_registry_interfaces__srv__RegistrationInterface_Request));
  bool success = services_registry_interfaces__srv__RegistrationInterface_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
services_registry_interfaces__srv__RegistrationInterface_Request__destroy(services_registry_interfaces__srv__RegistrationInterface_Request * msg)
{
  if (msg) {
    services_registry_interfaces__srv__RegistrationInterface_Request__fini(msg);
  }
  free(msg);
}


bool
services_registry_interfaces__srv__RegistrationInterface_Request__Sequence__init(services_registry_interfaces__srv__RegistrationInterface_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  services_registry_interfaces__srv__RegistrationInterface_Request * data = NULL;
  if (size) {
    data = (services_registry_interfaces__srv__RegistrationInterface_Request *)calloc(size, sizeof(services_registry_interfaces__srv__RegistrationInterface_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = services_registry_interfaces__srv__RegistrationInterface_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        services_registry_interfaces__srv__RegistrationInterface_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
services_registry_interfaces__srv__RegistrationInterface_Request__Sequence__fini(services_registry_interfaces__srv__RegistrationInterface_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      services_registry_interfaces__srv__RegistrationInterface_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

services_registry_interfaces__srv__RegistrationInterface_Request__Sequence *
services_registry_interfaces__srv__RegistrationInterface_Request__Sequence__create(size_t size)
{
  services_registry_interfaces__srv__RegistrationInterface_Request__Sequence * array = (services_registry_interfaces__srv__RegistrationInterface_Request__Sequence *)malloc(sizeof(services_registry_interfaces__srv__RegistrationInterface_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = services_registry_interfaces__srv__RegistrationInterface_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
services_registry_interfaces__srv__RegistrationInterface_Request__Sequence__destroy(services_registry_interfaces__srv__RegistrationInterface_Request__Sequence * array)
{
  if (array) {
    services_registry_interfaces__srv__RegistrationInterface_Request__Sequence__fini(array);
  }
  free(array);
}

bool
services_registry_interfaces__srv__RegistrationInterface_Request__Sequence__are_equal(const services_registry_interfaces__srv__RegistrationInterface_Request__Sequence * lhs, const services_registry_interfaces__srv__RegistrationInterface_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!services_registry_interfaces__srv__RegistrationInterface_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
services_registry_interfaces__srv__RegistrationInterface_Request__Sequence__copy(
  const services_registry_interfaces__srv__RegistrationInterface_Request__Sequence * input,
  services_registry_interfaces__srv__RegistrationInterface_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(services_registry_interfaces__srv__RegistrationInterface_Request);
    services_registry_interfaces__srv__RegistrationInterface_Request * data =
      (services_registry_interfaces__srv__RegistrationInterface_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!services_registry_interfaces__srv__RegistrationInterface_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          services_registry_interfaces__srv__RegistrationInterface_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!services_registry_interfaces__srv__RegistrationInterface_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
services_registry_interfaces__srv__RegistrationInterface_Response__init(services_registry_interfaces__srv__RegistrationInterface_Response * msg)
{
  if (!msg) {
    return false;
  }
  // value_returned
  return true;
}

void
services_registry_interfaces__srv__RegistrationInterface_Response__fini(services_registry_interfaces__srv__RegistrationInterface_Response * msg)
{
  if (!msg) {
    return;
  }
  // value_returned
}

bool
services_registry_interfaces__srv__RegistrationInterface_Response__are_equal(const services_registry_interfaces__srv__RegistrationInterface_Response * lhs, const services_registry_interfaces__srv__RegistrationInterface_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // value_returned
  if (lhs->value_returned != rhs->value_returned) {
    return false;
  }
  return true;
}

bool
services_registry_interfaces__srv__RegistrationInterface_Response__copy(
  const services_registry_interfaces__srv__RegistrationInterface_Response * input,
  services_registry_interfaces__srv__RegistrationInterface_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // value_returned
  output->value_returned = input->value_returned;
  return true;
}

services_registry_interfaces__srv__RegistrationInterface_Response *
services_registry_interfaces__srv__RegistrationInterface_Response__create()
{
  services_registry_interfaces__srv__RegistrationInterface_Response * msg = (services_registry_interfaces__srv__RegistrationInterface_Response *)malloc(sizeof(services_registry_interfaces__srv__RegistrationInterface_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(services_registry_interfaces__srv__RegistrationInterface_Response));
  bool success = services_registry_interfaces__srv__RegistrationInterface_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
services_registry_interfaces__srv__RegistrationInterface_Response__destroy(services_registry_interfaces__srv__RegistrationInterface_Response * msg)
{
  if (msg) {
    services_registry_interfaces__srv__RegistrationInterface_Response__fini(msg);
  }
  free(msg);
}


bool
services_registry_interfaces__srv__RegistrationInterface_Response__Sequence__init(services_registry_interfaces__srv__RegistrationInterface_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  services_registry_interfaces__srv__RegistrationInterface_Response * data = NULL;
  if (size) {
    data = (services_registry_interfaces__srv__RegistrationInterface_Response *)calloc(size, sizeof(services_registry_interfaces__srv__RegistrationInterface_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = services_registry_interfaces__srv__RegistrationInterface_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        services_registry_interfaces__srv__RegistrationInterface_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
services_registry_interfaces__srv__RegistrationInterface_Response__Sequence__fini(services_registry_interfaces__srv__RegistrationInterface_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      services_registry_interfaces__srv__RegistrationInterface_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

services_registry_interfaces__srv__RegistrationInterface_Response__Sequence *
services_registry_interfaces__srv__RegistrationInterface_Response__Sequence__create(size_t size)
{
  services_registry_interfaces__srv__RegistrationInterface_Response__Sequence * array = (services_registry_interfaces__srv__RegistrationInterface_Response__Sequence *)malloc(sizeof(services_registry_interfaces__srv__RegistrationInterface_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = services_registry_interfaces__srv__RegistrationInterface_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
services_registry_interfaces__srv__RegistrationInterface_Response__Sequence__destroy(services_registry_interfaces__srv__RegistrationInterface_Response__Sequence * array)
{
  if (array) {
    services_registry_interfaces__srv__RegistrationInterface_Response__Sequence__fini(array);
  }
  free(array);
}

bool
services_registry_interfaces__srv__RegistrationInterface_Response__Sequence__are_equal(const services_registry_interfaces__srv__RegistrationInterface_Response__Sequence * lhs, const services_registry_interfaces__srv__RegistrationInterface_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!services_registry_interfaces__srv__RegistrationInterface_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
services_registry_interfaces__srv__RegistrationInterface_Response__Sequence__copy(
  const services_registry_interfaces__srv__RegistrationInterface_Response__Sequence * input,
  services_registry_interfaces__srv__RegistrationInterface_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(services_registry_interfaces__srv__RegistrationInterface_Response);
    services_registry_interfaces__srv__RegistrationInterface_Response * data =
      (services_registry_interfaces__srv__RegistrationInterface_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!services_registry_interfaces__srv__RegistrationInterface_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          services_registry_interfaces__srv__RegistrationInterface_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!services_registry_interfaces__srv__RegistrationInterface_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
