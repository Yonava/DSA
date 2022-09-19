

-- @BLOCK
CREATE TABLE Cities(
  id INT PRIMARY KEY AUTO_INCREMENT,
  cityName VARCHAR(255) NOT NULL,
  timeZone CHAR(3),
  populationSize INT NOT NULL,
  surfaceArea INT NOT NULL
);

-- @BLOCK 
SELECT * FROM Cities;

-- @BLOCK
INSERT INTO Cities (cityName, timeZone, populationSize, surfaceArea)
VALUES (
  'Portland',
  'PST',
  650000,
  145
);

-- @BLOCK
UPDATE Cities SET
  timeZone = 'PST'
  WHERE cityName = 'San Francisco';

-- @BLOCK
CREATE TABLE Countries(
  id INT PRIMARY KEY AUTO_INCREMENT,
  populationSize INT NOT NULL,
  surfaceArea INT NOT NULL,
  countryName VARCHAR(255) NOT NULL,
  countryCode CHAR(2) NOT NULL,
  primaryLanguage VARCHAR(255),
  politicalSystem VARCHAR(255)
);

