<?php
    
    // Acá están las credenciales para conectar a la base
    require_once( "db.php" );

    $DB_conn = mysqli_connect( $host, $DB_user, $DB_pass, $DB_name );


    // Esto corresponde a un URL como la siguiente:
    // https://www.cesarosimani.com.ar/poo/api.php?usuario=cosimani&clave=1234
    if ( isset( $_GET[ 'usuario' ] ) && isset( $_GET[ 'clave' ] ) )  {
        
        $query = mysqli_query( $DB_conn, "SELECT nombre, apellido, mail FROM osi_usuarios " . 
                                         "WHERE usuario = '" . $_GET[ 'usuario' ] . "' AND clave = '" . $_GET[ 'clave' ] . "'" );

        $row = mysqli_fetch_array( $query );

        $num_row    = mysqli_num_rows( $query );
                        
        if ( $num_row == 1 )  {   
            print( "aceptado::" . $row[ 'nombre' ] . "::" . $row[ 'apellido' ] . "::" . $row[ 'mail' ] );
        }
        else  {
            print( "denegado" ); 
        }

    }

?>
