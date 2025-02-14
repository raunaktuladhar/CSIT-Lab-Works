<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="qno2.aspx.cs" Inherits="Project2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Raunak Tuladhar (28569/078)</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="l1" Text ="Enter First Number: " runat="server"></asp:Label>
            <asp:TextBox ID="inp1" runat="server"></asp:TextBox> 
            <asp:RequiredFieldValidator ID="i1" ControlToValidate="inp1" ErrorMessage="Text Box can't be empty" ForeColor="Red" runat="server"></asp:RequiredFieldValidator><br /><br />

            <asp:Label ID="l2" Text="Enter Second Number: " runat="server"></asp:Label>
            <asp:TextBox ID="inp2" runat="server"></asp:TextBox>
            <asp:RequiredFieldValidator ID="i2" ControlToValidate="inp2" ErrorMessage="Text Box can't be empty" ForeColor="Red" runat="server"></asp:RequiredFieldValidator><br /><br />

            <asp:Button ID="btn_add" runat="server" Text="Add" OnClick="btn_add_click" />
            <asp:Button ID="btn_sub" runat="server" Text="Subtract" OnClick="btn_sub_click" />
            <asp:Button ID="btn_prime" runat="server" Text="Find Prime" OnClick="btn_prime_click" />
            <br /><br />

            <asp:Label ID="l3" Text="Result: " runat="server"></asp:Label>
            <asp:TextBox ID="out1" runat="server"></asp:TextBox>
        </div>
    </form>
</body>
</html>
