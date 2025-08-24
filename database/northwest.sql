-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Aug 24, 2025 at 02:32 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `northwest`
--

-- --------------------------------------------------------

--
-- Table structure for table `accounts`
--

CREATE TABLE `accounts` (
  `#` int(11) NOT NULL,
  `Account_Name` varchar(32) NOT NULL,
  `Account_Password` varchar(80) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `accounts`
--

INSERT INTO `accounts` (`#`, `Account_Name`, `Account_Password`) VALUES
(1, 'Noice', '$2b$12$YgV9ot4GtYTCxO7wQ1zY0exGy/a5JLJ4lNa864/JqJ2rBiozpGFOS');

-- --------------------------------------------------------

--
-- Table structure for table `players`
--

CREATE TABLE `players` (
  `Player_ID` int(11) NOT NULL,
  `Account_Name` varchar(32) NOT NULL,
  `Player_Name` varchar(24) NOT NULL,
  `Player_World` int(11) NOT NULL DEFAULT 0,
  `Player_Interior` int(11) NOT NULL DEFAULT 0,
  `Player_Skin` int(11) NOT NULL,
  `Player_LastLogin` varchar(32) NOT NULL,
  `Player_PosX` float NOT NULL,
  `Player_PosY` float NOT NULL,
  `Player_PosZ` float NOT NULL,
  `Player_Angle` float NOT NULL,
  `Player_Health` float NOT NULL DEFAULT 100,
  `Player_Armour` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `players`
--

INSERT INTO `players` (`Player_ID`, `Account_Name`, `Player_Name`, `Player_World`, `Player_Interior`, `Player_Skin`, `Player_LastLogin`, `Player_PosX`, `Player_PosY`, `Player_PosZ`, `Player_Angle`, `Player_Health`, `Player_Armour`) VALUES
(4, 'Noice', 'Jhon_Doe', 0, 0, 3, '2025-08-22 00:57:25', 61.3034, 48.1471, 0.665392, 259.961, 100, 0),
(7, 'Noice', 'Mark_Zuu', 0, 0, 3, '2025-08-19 19:22:45', 60.7294, 52.9216, 0.904752, 173.414, 100, 0);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `accounts`
--
ALTER TABLE `accounts`
  ADD PRIMARY KEY (`#`);

--
-- Indexes for table `players`
--
ALTER TABLE `players`
  ADD PRIMARY KEY (`Player_ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `accounts`
--
ALTER TABLE `accounts`
  MODIFY `#` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `players`
--
ALTER TABLE `players`
  MODIFY `Player_ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
