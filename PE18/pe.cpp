/*
	Alberto Sola
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

/*
	Read file into std::vector<string>.
	
	file_name : file name string ( char * )
	v_out : vector where storing lines.
	
*/
void ReadFile( const char * const file_name, std::vector< string > & v_out ){
	
	// Open file
	ifstream file_in( file_name );
	string line_readed;
	
	while( getline( file_in, line_readed ) )
		v_out.push_back( line_readed );	
	
	file_in.close();
	
}

void ReadFile( const char * const file_name, std::vector< vector<int> > & v_out ){
	
	// Open file
	ifstream file_in( file_name );
	istringstream line_readed;
	string line;
	
	int index = 0;
	int number;
	
	while( getline( file_in, line ) ){
		
		line_readed.str( line );
		
		//cout << "Linea " << index << endl;
		//cout << "Contenido: " << line_readed.str() << endl;
		//cout << "Fail: " << line_readed.fail()<< endl;
		
		while( line_readed >> number ){
			v_out[index].push_back( number );
			//cout << number << ", ";
		}
		
		cout << endl;
		
		line_readed.clear();
		index++;
				
	}
	
	file_in.close();
	
}

int getMaxSumPath( const vector<vector<int>> & tree ){
	
	vector<int> max_sum;
	
	int size = tree.size();
	
	for( int fil = size - 1; fil >= 0; fil++ ){
		for( int col = 0; col < fil; col++ ){
			
			
			
		}
	}	
	
}

int main(){
	
	vector< vector<int> > file;
	int size;
	int end;
	
	file.resize(100);
	
	ReadFile( "tree.txt", file );
	
	/*
	size = file.size();
	
	for( int i = 0; i < size; i++ ){
		
		end = file[i].size();
		
		for( int j = 0; j < end; j++ )
			cout << file[i][j] << " ";
		cout << endl;
	}
	*/
	return 0;
}
