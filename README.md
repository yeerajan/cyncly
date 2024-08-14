### Affine Transformation

An affine transformation is a linear mapping method that preserves points, straight lines, and planes. 
Common examples of affine transformations include translation, rotation, scaling, and shearing. 
In computer graphics and geometry, affine transformations are crucial because they preserve the 
"affineness" of a shape, meaning parallel lines remain parallel after transformation, and ratios of distances along parallel lines are preserved.

Affine transformations can be represented by a matrix multiplication followed by a translation vector, typically in homogeneous coordinates. 
This allows a series of transformations to be combined into a single matrix operation, making it efficient to apply multiple transformations to a point or object in space.

### Quaternion

A quaternion is a mathematical concept that extends complex numbers to four dimensions, often used in 3D computer graphics
to represent rotations. Unlike Euler angles, quaternions avoid the problem of gimbal lock and provide smooth interpolation 
between rotations (spherical linear interpolation, or "slerp").

A quaternion is expressed as \( q = w + xi + yj + zk \), where \( w \), \( x \), \( y \), 
and \( z \) are real numbers, and \( i \), \( j \), and \( k \) are the fundamental quaternion units. 
Quaternions are particularly powerful for 3D rotations because they can represent any rotation in 3D space as a single, 
compact entity, and they are more numerically stable than matrices for repeated calculations.
