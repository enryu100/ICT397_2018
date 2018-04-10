/**
* Types.h
*
* Author: Brandon Lim
*
* Defines a set of types for use in calculations on transformations in 3D space.
*
* Vectors of three types and a matrix type.
*/
#pragma once

#include <math.h>

namespace types{
	/**
	* @struct Vector2D
	* @brief A struct that defines a vector in two-dimensional space.
	*
	* The Vector2D struct is merely a data type that represents a vector in two-dimensional
	* space, providing a few functions to assist with spatial calculations. At present, it
	* does not appear to be used.
	*
	* @author Brandon Lim
	*/
	struct Vector2D{
		/// The x-axis value of the vector.
		float x;
		/// The y-axis value of the vector.
		float y;

		/**
		* The constructor for a Vector2D variable.
		* Initialises the x and y values.
		*/
		Vector2D(){
			x = 0.0f;
			y = 0.0f;
		}

		/**
		* Another constructor for a Vector2D variable.
		* Initialises the x and y values with xx and yy respectively.
		*/
		Vector2D(float xx, float yy){
			x = xx;
			y = yy;
		}

		/**
		* @brief Gets the length of the vector.
		* @return float - The vector's length as a floating-point number
		*
		* length calculates and returns the length of the vector using its x and y values.
		*/
		float length(){
			return (sqrt(x*x + y*y));
		}

		/**
		* @brief Gets the normalised version of the vector.
		* @return Vector2D - The normalised vector
		*
		* normalise calculates and returns the normalised version of the vector using its x
		* and y values.
		*/
		Vector2D normalise(){
			Vector2D normalVec = Vector2D();
			float length = this->length();

			if(length != 0){
				normalVec.x = x / length;
				normalVec.y = y / length;
			}

			return normalVec;
		}
	};

	/**
	* @struct Vector3D
	* @brief A struct that defines a vector in three-dimensional space.
	*
	* The Vector3D struct is merely a data type that represents a vector in three-
	* dimensional space, providing a few functions to assist with spatial calculations.
	*
	* @author Brandon Lim
	*/
	struct Vector3D{
		/// The x-axis value of the vector.
		float x;
		/// The y-axis value of the vector.
		float y;
		/// The z-axis value of the vector.
		float z;

		/**
		* The constructor for a Vector3D variable.
		* Initialises the x, y, and z values.
		*/
		Vector3D(){
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		/**
		* Another constructor for a Vector3D variable.
		* Initialises the x, y, and z values with xx, yy, and zz respectively.
		*/
		Vector3D(float xx, float yy, float zz){
			x = xx;
			y = yy;
			z = zz;
		}

		/**
		* @brief Gets the length of the vector.
		* @return float - The vector's length as a floating-point number
		*
		* length calculates and returns the length of the vector using its x, y, and z
		* values.
		*/
		float length(){
			return (sqrt(x*x + y*y + z*z));
		}
		
		/**
		* @brief Finds and returns the greatest value of each x, y, z for 2 vector3D
		* @return Vector3D - contains greatest values of each point in the vector
		* @param r - &Vector3D
		*/
		 Vector3D max(Vector3D & r){
		  Vector3D result;
		  if(r.x > this->x){
			  result.x = r.x;
		  }else{
			  result.x = this->x;
		  }
		  
		  if(r.y > this->y){
			  
			  result.y = r.y; 
		  }else{
			  result.y = this->y;
		  }

		  if(r.z > this->z){
			  result.z = r.z;
		  }else{
			  result.z = this->z;
		  }
		  return result;
		 }

		 /**
		* @brief Finds and returns the greatest value in the vector
		* @return float - biggest value in the vector
		*/
		 float max(){
			 if(this->x>this->y && this->x > this->z){
				 return this->x;
			 }else if(this->y>this->x && this->y > this->z){
				 return this->y;
			 }else {
				 return this->z;
			 }

		 }
		/**
		* @brief Gets the normalised version of the vector.
		* @return Vector3D - The normalised vector
		*
		* normalise calculates and returns the normalised version of the vector using its x,
		* y, and z values.
		*/
		Vector3D normalise(){
			Vector3D normalVec = Vector3D();
			float length = this->length();

			if(length != 0){
				normalVec.x = x / length;
				normalVec.y = y / length;
				normalVec.z = z / length;
			}

			return normalVec;
		}

		/**
		* @brief Gets the cross product of this and another vector.
		* @return Vector3D - The vector at right angles to this and the other vector
		*
		* crossProduct calculates and returns the vector at right angles to this vector and
		* another passed as a parameter using their x, y, and z values.
		*/
		Vector3D crossProduct(Vector3D otherVec){
			Vector3D crossVec;

			crossVec.x = (this->y * otherVec.z) + (this->z * otherVec.y);
			crossVec.y = (this->z * otherVec.x) + (this->x * otherVec.z);
			crossVec.z = (this->x * otherVec.y) + (this->y * otherVec.x);

			return crossVec;
		}
	};

	/**
	* @struct Vector4D
	* @brief A struct that defines a vector in three-dimensional space with an extra value
	* that defines whether it is a point or a proper vector.
	*
	* The Vector4D struct is a data type that represents a vector or point in three-
	* dimensional space, the two of which can be discerned between with the w-value. A few
	* functions are provided to assist with spatial calculations. This type was created so
	* that 3D vectors could be used in matrix multiplication.
	*
	* @author Brandon Lim
	*/
	struct Vector4D{
		float x;
		float y;
		float z;
		float w;

		/**
		* The constructor for a Vector4D variable.
		* Initialises the x, y, z, and w values.
		*/
		Vector4D(){
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 1.0f;
		}

		/**
		* Another constructor for a Vector4D variable.
		* Initialises the x, y, z, and w values with xx, yy, zz, and ww respectively.
		*/
		Vector4D(float xx, float yy, float zz, float ww){
			x = xx;
			y = yy;
			z = zz;
			w = ww;
		}

		/**
		* @brief Gets the length of the vector.
		* @return float - The vector's length as a floating-point number
		*
		* length calculates and returns the length of the vector (after determining if it
		* is a vector) using its x, y, and z values.
		*/
		float length(){
			if(z != 0.0f)
				return (sqrt(x*x + y*y + z*z));
			else
				return 0.0f;
		}

		/**
		* @brief Gets the normalised version of the vector.
		* @return Vector4D - The normalised vector
		*
		* normalise calculates and returns the normalised version of the vector using its x,
		* y, and z values.
		*/
		Vector4D normalise(){
			Vector4D normalVec = Vector4D();
			float length = this->length();

			if(length != 0){
				normalVec.x = x / length;
				normalVec.y = y / length;
				normalVec.z = z / length;
			}

			return normalVec;
		}
	};

	/**
	* @struct Matrix4x4
	* @brief A struct that defines a four-dimensional matrix.
	*
	* The Matrix4x4 struct is a data type that represents a four-dimensional matrix. This is
	* useful for spatial calculations or for storing four-dimensional vectors.
	*
	* @author Brandon Lim
	*/
	struct Matrix4x4{
		/// The columns of the matrix.
		Vector4D columns[4];

		/**
		* The constructor for a Matrix4x4 variable.
		* Initialises all of the elements of the matrix.
		*/
		Matrix4x4(){
			columns[0] = Vector4D(1, 0, 0, 0);
			columns[1] = Vector4D(0, 1, 0, 0);
			columns[2] = Vector4D(0, 0, 1, 0);
			columns[3] = Vector4D(0, 0, 0, 1);
		}

		/**
		* Another constructor for a Matrix4x4 variable.
		* Initialises the columns of the matrix with col1, col2, col3, and col4.
		*/
		Matrix4x4(Vector4D col1, Vector4D col2, Vector4D col3, Vector4D col4){
			columns[0] = col1;
			columns[1] = col2;
			columns[2] = col3;
			columns[3] = col4;
		}
	};

	/**
	* @brief An overridden multiplication operator for matrix * vector calculations.
	* @param m - The matrix to be multiplied
	* @param v - The vector to be multiplied
	* @return Vector4D - The vector resulting from the operation
	*
	* This simply overrides the multiplication operator to reflect how pre-multiplying a
	* vector with a matrix operates.
	*/
	Vector4D operator*(const Matrix4x4& m, const Vector4D& v);
	/**
	* @brief An overridden multiplication operator for vector * matrix calculations.
	* @param v - The vector to be multiplied
	* @param m - The matrix to be multiplied
	* @return Vector4D - The vector resulting from the operation
	*
	* This simply overrides the multiplication operator to reflect how post-multiplying a
	* vector with a matrix operates.
	*/
	Vector4D operator*(const Vector4D& v, const Matrix4x4& m);
	/**
	* @brief An overridden multiplication operator for matrix multiplication.
	* @param m1 - The matrix to be pre-multiplied
	* @param m2 - The matrix to be post-multiplied
	* @return Matrix4x4 - The matrix resulting from the operation
	*
	* This simply overrides the multiplication operator to reflect how matrix multiplication
	* operates.
	*/
	Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2);
}

