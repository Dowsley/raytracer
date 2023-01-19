# Raytracer
This is being made by thankfully following the teachings in [Ray Tracing In One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html).

I intend to make this project have its own personality with some 90s/dreamcore/frutiger aero graphics.

And... implement this in the Pixel Game Engine!

## TODOs:
- [X] Implement core classes
- [X] Add PPM image output
- [X] Add progress indicator
- [X] Add core structures for vector operations
- [X] Cast the first rays
- [X] Antialiasing
- [X] Diffuse surfaces
- [X] Reflection
- [X] Reimplement rendering on the Pixel Game Engine
  - [X] With the PPM image output as an option
- [X] Refraction
- [ ] Positionable camera
- [ ] Controllable camera
  - [ ] Implement cheaper, real time rendering
- [ ] Optimize with GPU, parallelized rendering? 
- [ ] Add support to more complex shapes
- [ ] Make it usable
  - Interface?
  - Modifiable Geometry mid-run
  - Decoupled, loadable data for geometry and other parameters (cam, etc)

## Known Bugs
1. Negative Radius sphere of material dielectric gives off unexpected reflections on borders.
  - Maybe it's expected. My rendering had a higher max_depth than in the guide.