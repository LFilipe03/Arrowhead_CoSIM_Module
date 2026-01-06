# generated from rosidl_generator_py/resource/_idl.py.em
# with input from services_registry_interfaces:srv/RegistrationInterface.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RegistrationInterface_Request(type):
    """Metaclass of message 'RegistrationInterface_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('services_registry_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'services_registry_interfaces.srv.RegistrationInterface_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__registration_interface__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__registration_interface__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__registration_interface__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__registration_interface__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__registration_interface__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RegistrationInterface_Request(metaclass=Metaclass_RegistrationInterface_Request):
    """Message class 'RegistrationInterface_Request'."""

    __slots__ = [
        '_registration_data_json',
        '_service_id_with_update',
        '_method',
    ]

    _fields_and_field_types = {
        'registration_data_json': 'string',
        'service_id_with_update': 'int32',
        'method': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.registration_data_json = kwargs.get('registration_data_json', str())
        self.service_id_with_update = kwargs.get('service_id_with_update', int())
        self.method = kwargs.get('method', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.registration_data_json != other.registration_data_json:
            return False
        if self.service_id_with_update != other.service_id_with_update:
            return False
        if self.method != other.method:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def registration_data_json(self):
        """Message field 'registration_data_json'."""
        return self._registration_data_json

    @registration_data_json.setter
    def registration_data_json(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'registration_data_json' field must be of type 'str'"
        self._registration_data_json = value

    @property
    def service_id_with_update(self):
        """Message field 'service_id_with_update'."""
        return self._service_id_with_update

    @service_id_with_update.setter
    def service_id_with_update(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'service_id_with_update' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'service_id_with_update' field must be an integer in [-2147483648, 2147483647]"
        self._service_id_with_update = value

    @property
    def method(self):
        """Message field 'method'."""
        return self._method

    @method.setter
    def method(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'method' field must be of type 'str'"
        self._method = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_RegistrationInterface_Response(type):
    """Metaclass of message 'RegistrationInterface_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('services_registry_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'services_registry_interfaces.srv.RegistrationInterface_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__registration_interface__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__registration_interface__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__registration_interface__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__registration_interface__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__registration_interface__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RegistrationInterface_Response(metaclass=Metaclass_RegistrationInterface_Response):
    """Message class 'RegistrationInterface_Response'."""

    __slots__ = [
        '_value_returned',
    ]

    _fields_and_field_types = {
        'value_returned': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.value_returned = kwargs.get('value_returned', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.value_returned != other.value_returned:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def value_returned(self):
        """Message field 'value_returned'."""
        return self._value_returned

    @value_returned.setter
    def value_returned(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'value_returned' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'value_returned' field must be an integer in [-2147483648, 2147483647]"
        self._value_returned = value


class Metaclass_RegistrationInterface(type):
    """Metaclass of service 'RegistrationInterface'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('services_registry_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'services_registry_interfaces.srv.RegistrationInterface')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__registration_interface

            from services_registry_interfaces.srv import _registration_interface
            if _registration_interface.Metaclass_RegistrationInterface_Request._TYPE_SUPPORT is None:
                _registration_interface.Metaclass_RegistrationInterface_Request.__import_type_support__()
            if _registration_interface.Metaclass_RegistrationInterface_Response._TYPE_SUPPORT is None:
                _registration_interface.Metaclass_RegistrationInterface_Response.__import_type_support__()


class RegistrationInterface(metaclass=Metaclass_RegistrationInterface):
    from services_registry_interfaces.srv._registration_interface import RegistrationInterface_Request as Request
    from services_registry_interfaces.srv._registration_interface import RegistrationInterface_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
