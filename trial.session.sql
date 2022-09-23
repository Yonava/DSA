

-- @BLOCK
CREATE TABLE Cities(
  id INT AUTO_INCREMENT,
  cityName VARCHAR(255) NOT NULL,
  countryID INT,
  timeZone CHAR(3),
  populationSize INT NOT NULL,
  surfaceArea INT NOT NULL,
  PRIMARY KEY (id),
  FOREIGN KEY (countryID) REFERENCES Countries(id)
);

-- @BLOCK
SELECT * FROM Cities WHERE timeZone = 'PST';

-- @BLOCK
INSERT INTO Cities (cityName, countryID, timeZone, populationSize, surfaceArea)
VALUES (
  'Nice',
  3,
  'CET',
  10000000,
  700
);

-- @BLOCK
DROP TABLE Cities;

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

-- @BLOCK
INSERT INTO Countries (populationSize, surfaceArea, countryName, countryCode, primaryLanguage, politicalSystem)
VALUES (
  10000000,
  1200000,
  'Canada',
  'CA',
  'English',
  'Parlimentary'
),
 (
  2000000,
  1240000,
  'Switzerland',
  'CH',
  'German',
  'Direct Democracy'
),

 (
  4000000,
  400000,
  'Austria',
  'AT',
  'German',
  'Parlimentary'
);

-- @BLOCK
SELECT * FROM Countries;

