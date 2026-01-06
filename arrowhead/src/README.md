## Traffic Service Example

1. ```ros2 run services_registry server registryServer1```

2. ```ros2 run cpp_pubsub traffic cpp_pubsub/src/files/ServiceTraffic1.json 10 registryServer1```

3. ```ros2 run services_discovery server discoveryServer1```

4. ```ros2 run car_package traffic car_package/src/files/CarPath1.json car_package/src/files/ServicesTraffic.json discoveryServer1```

5. ```ros2 run car_package simulation car_package/src/files/Simulation1.json```


## Police Service Example

1. ```ros2 run services_registry server registryServer1```

2. ```ros2 run cpp_pubsub police cpp_pubsub/src/files/ServicePolice1.json 10 registryServer1```

3. ```ros2 run services_discovery server discoveryServer1```

4. ```ros2 run car_package police car_package/src/files/CarPath1.json car_package/src/files/ServicesPolice.json discoveryServer1```

5. ```ros2 run car_package simulation car_package/src/files/Simulation1.json```

## Police and Traffic Service Same RSU and Same Vehicle Example

1. ```ros2 run services_registry server registryServer1```

2. ```ros2 run cpp_pubsub police cpp_pubsub/src/files/ServicePolice2.json 10 registryServer1```

3. ```ros2 run cpp_pubsub traffic cpp_pubsub/src/files/ServiceTraffic3.json 10 registryServer1```

4. ```ros2 run services_discovery server discoveryServer1```

5. ```ros2 run car_package police car_package/src/files/CarPath1.json car_package/src/files/ServicesPolice.json discoveryServer1```

6. ```ros2 run car_package traffic car_package/src/files/CarPath1.json car_package/src/files/ServicesTraffic.json discoveryServer1```

7. ```ros2 run car_package simulation car_package/src/files/Simulation1.json```

## Police with Different RSU and Different Vehicle Example

1. ```ros2 run services_registry server registryServer1```

2. ```ros2 run cpp_pubsub police cpp_pubsub/src/files/ServicePolice1.json 10 registryServer1```

3. ```ros2 run services_registry server registryServer2```

4. ```ros2 run cpp_pubsub police cpp_pubsub/src/files/ServicePolice2.json 10 registryServer2```

5. ```ros2 run services_discovery server discoveryServer1```

6. ```ros2 run car_package police car_package/src/files/CarPath1.json car_package/src/files/ServicesPolice.json discoveryServer1```

7. ```ros2 run services_discovery server discoveryServer2```

8. ```ros2 run car_package traffic car_package/src/files/CarPath2.json car_package/src/files/ServicesTraffic.json discoveryServer2```

9. ```ros2 run car_package simulation car_package/src/files/Simulation1.json```

10. ```ros2 run car_package simulation car_package/src/files/Simulation2.json```