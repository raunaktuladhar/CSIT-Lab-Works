-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3307
-- Generation Time: Apr 17, 2024 at 06:39 AM
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
-- Database: `ims_db`
--

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `CustomerID` char(5) NOT NULL,
  `CustomerName` varchar(50) NOT NULL,
  `CustomerAddress` varchar(50) NOT NULL,
  `CustomerPhoneNo` char(20) NOT NULL,
  `CustomerEmail` varchar(50) NOT NULL,
  `CustomerDOB` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`CustomerID`, `CustomerName`, `CustomerAddress`, `CustomerPhoneNo`, `CustomerEmail`, `CustomerDOB`) VALUES
('C1', 'Abhishek Sharma', '7TH Cross, Janakpuri', '9088801001', 'asharma@gmail.com', '1996-01-10'),
('C2', 'Rinku Sharma', 'HNO-8205', '809881077', 'rinku@gmail.com', '1999-04-10'),
('C3', 'Teena Mathew', 'DLF, Phase 5', '9880601077', 'teena@yahoo.com', '1990-06-29'),
('C4', 'Roshan Singh', 'Flat No. 6A, Rajdur Road', '6767601123', 'roshan@outlook.com', '1996-08-20'),
('C5', 'Monika Babi', 'Pocket 2, Sector 11', '5577640107', 'monika@gmail.com', '1997-07-20');

-- --------------------------------------------------------

--
-- Table structure for table `orders`
--

CREATE TABLE `orders` (
  `OrderID` char(5) NOT NULL,
  `OrderDate` date NOT NULL,
  `CustomerID` char(5) NOT NULL,
  `ProductID` char(5) NOT NULL,
  `OrderQuantity` decimal(10,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `orders`
--

INSERT INTO `orders` (`OrderID`, `OrderDate`, `CustomerID`, `ProductID`, `OrderQuantity`) VALUES
('O1', '2018-07-15', 'C5', 'P1', 1.00),
('O2', '2017-08-02', 'C2', 'P4', 4.00),
('O3', '2016-01-07', 'C1', 'P2', 2.00),
('O4', '1998-07-05', 'C4', 'P5', 7.00),
('O5', '2018-07-15', 'C3', 'P3', 3.00);

-- --------------------------------------------------------

--
-- Table structure for table `product`
--

CREATE TABLE `product` (
  `ProductID` char(5) NOT NULL,
  `ProductName` varchar(50) NOT NULL,
  `Price` decimal(10,2) NOT NULL,
  `Category` char(5) NOT NULL,
  `SupplierID` char(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `product`
--

INSERT INTO `product` (`ProductID`, `ProductName`, `Price`, `Category`, `SupplierID`) VALUES
('P1', 'HP Laptop and Charger', 6000.00, 'IT', 'S1'),
('P2', 'Mixer Grinder', 10000.00, 'HA', 'S5'),
('P3', 'Mobile Phone', 4000.00, 'IT', 'S4'),
('P4', 'Steamer', 400.00, 'HC', 'S2'),
('P5', 'Chairs and Tables', 10500.00, 'HA', 'S3');

-- --------------------------------------------------------

--
-- Table structure for table `stock`
--

CREATE TABLE `stock` (
  `StockID` char(5) NOT NULL,
  `ProductID` char(5) NOT NULL,
  `StockQuantity` int(11) DEFAULT NULL,
  `ReorderLevel` int(11) DEFAULT NULL,
  `MinimumOrderQuantity` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `stock`
--

INSERT INTO `stock` (`StockID`, `ProductID`, `StockQuantity`, `ReorderLevel`, `MinimumOrderQuantity`) VALUES
('ST1', 'P5', 3, 4, 8),
('ST2', 'P2', 2, 5, 20),
('ST3', 'P4', 5, 3, 15),
('ST4', 'P1', 0, 1, 10),
('ST5', 'P5', 6, 2, 12);

-- --------------------------------------------------------

--
-- Table structure for table `supplier`
--

CREATE TABLE `supplier` (
  `SupplierID` char(5) NOT NULL,
  `SupplierName` varchar(50) NOT NULL,
  `SupplierAddress` varchar(50) NOT NULL,
  `SupplierPhoneNo` char(20) NOT NULL,
  `SupplierEmail` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `supplier`
--

INSERT INTO `supplier` (`SupplierID`, `SupplierName`, `SupplierAddress`, `SupplierPhoneNo`, `SupplierEmail`) VALUES
('S1', 'HP World', 'Sector 11 Dwarka', '9999001001', 'hpworld@gmail.com'),
('S2', 'Medcare', 'SC Kanpur, NP Road', '8887001222', 'medcare@gmail.com'),
('S3', 'Retail Shoppers', 'B1/45, Janakpuri', '3337001333', 'retailshop@yahoo.com.in'),
('S4', 'IT Pickup', 'DLF, Phase 5', '703331343', 'itpickup@gmail.com'),
('S5', 'Home Finisher', 'C2-431, Supertech', '99003388', 'homefinish@outlook.com');

-- --------------------------------------------------------

--
-- Stand-in structure for view `view2`
-- (See below for the actual view)
--
CREATE TABLE `view2` (
`CustomerID` char(5)
,`ProductID` char(5)
);

-- --------------------------------------------------------

--
-- Structure for view `view2`
--
DROP TABLE IF EXISTS `view2`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `view2`  AS SELECT `orders`.`CustomerID` AS `CustomerID`, `orders`.`ProductID` AS `ProductID` FROM `orders` WHERE `orders`.`OrderID` = 'O1' ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`CustomerID`);

--
-- Indexes for table `orders`
--
ALTER TABLE `orders`
  ADD PRIMARY KEY (`OrderID`),
  ADD KEY `CustomerID` (`CustomerID`),
  ADD KEY `ProductID` (`ProductID`);

--
-- Indexes for table `product`
--
ALTER TABLE `product`
  ADD PRIMARY KEY (`ProductID`),
  ADD KEY `SupplierID` (`SupplierID`);

--
-- Indexes for table `stock`
--
ALTER TABLE `stock`
  ADD PRIMARY KEY (`StockID`),
  ADD KEY `ProductID` (`ProductID`);

--
-- Indexes for table `supplier`
--
ALTER TABLE `supplier`
  ADD PRIMARY KEY (`SupplierID`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `orders`
--
ALTER TABLE `orders`
  ADD CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`CustomerID`) REFERENCES `customer` (`CustomerID`),
  ADD CONSTRAINT `orders_ibfk_2` FOREIGN KEY (`ProductID`) REFERENCES `product` (`ProductID`);

--
-- Constraints for table `product`
--
ALTER TABLE `product`
  ADD CONSTRAINT `product_ibfk_1` FOREIGN KEY (`SupplierID`) REFERENCES `supplier` (`SupplierID`);

--
-- Constraints for table `stock`
--
ALTER TABLE `stock`
  ADD CONSTRAINT `stock_ibfk_1` FOREIGN KEY (`ProductID`) REFERENCES `product` (`ProductID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
