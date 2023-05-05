DROP TABLE IF EXISTS `osi_usuarios`;

CREATE TABLE `osi_usuarios` (
  `usuario` varchar(50) NOT NULL,
  `clave` varchar(50) NOT NULL,
  `nombre` varchar(50) DEFAULT NULL,
  `apellido` varchar(50) DEFAULT NULL,
  `mail` varchar(100) DEFAULT NULL,

  PRIMARY KEY ( `usuario` ) USING BTREE

) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_general_ci;

INSERT INTO `osi_usuarios` ( `usuario`, `clave`, `nombre`, `apellido`, `mail` ) VALUES
( 'cosimani', '1234', 'César', 'Osimani', 'cesarosimani@gmail.com' );
