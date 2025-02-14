<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="qno4.aspx.cs" Inherits="Project2.WebForm2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Raunak Tuladhar(28569/078)</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="l1" Text="Id: " runat="server"></asp:Label>
            <asp:TextBox ID="uid" runat="server"></asp:TextBox>
            <asp:RequiredFieldValidator ID="rv1" ControlToValidate="uid" ErrorMessage="id cannot be empty" ForeColor="Red" runat="server"></asp:RequiredFieldValidator> <br /><br />

            <asp:Label ID="l2" Text="Username: " runat="server"></asp:Label>
            <asp:TextBox ID="uname" runat="server"></asp:TextBox>
            <asp:RequiredFieldValidator ID="rv2" ControlToValidate="uname" ErrorMessage="username cannot be empty" ForeColor="Red" runat="server"></asp:RequiredFieldValidator><br /><br />
       
            <asp:Label ID="l3" Text="Password: " runat="server"></asp:Label>
            <asp:TextBox ID="pass" TextMode="Password" runat="server"></asp:TextBox>
            <asp:RequiredFieldValidator ID="rv3" ControlToValidate="pass" ErrorMessage="password cannot be empty" ForeColor="Red" runat="server"></asp:RequiredFieldValidator><br /><br />

            <asp:Label ID="l4" Text="Repassword: " runat="server"></asp:Label>
            <asp:TextBox ID="repass" TextMode="Password" runat="server"></asp:TextBox>
            <asp:RequiredFieldValidator ID="rv4" ControlToValidate="repass" ErrorMessage="repass cannot be empty" ForeColor="Red" runat="server"></asp:RequiredFieldValidator>
            <asp:CompareValidator ID="rv5" ControlToValidate="repass" ControlToCompare="pass" ErrorMessage="pass and repass should be equal" ForeColor="Red" runat="server"></asp:CompareValidator><br /><br />

            <asp:Label ID="l5" Text="Gender: " runat="server"></asp:Label>
            <asp:RadioButton ID="rb1" GroupName="gender" value="male" runat="server" />Male
            <asp:RadioButton ID="rb2" GroupName="gender" value="female" runat="server" />Female<br /><br />

            <asp:Label ID="l6" Text="Course: " runat="server"></asp:Label>
            <asp:CheckBox ID="cb1"  value="CSIT" runat="server" />CSIT
            <asp:CheckBox ID="cb2"  value="BIM" runat="server" />BIM
            <asp:CheckBox ID="cb3"  value="BCA" runat="server" />BCA
            <asp:CheckBox ID="cb4"  value="CSIT" runat="server" />BBA<br /><br />

            <asp:Label ID="l7" Text="Country" runat="server"></asp:Label>
            <asp:DropDownList ID="coun" runat="server">
                <asp:ListItem Value="">Select your country</asp:ListItem>
                <asp:ListItem Value="Nepal">Nepal</asp:ListItem>
                <asp:ListItem Value="China">China</asp:ListItem>
                <asp:ListItem Value="Japan">Japan</asp:ListItem>
                <asp:ListItem Value="India">India</asp:ListItem>
                <asp:ListItem Value="other">Other</asp:ListItem>
            </asp:DropDownList><br /><br />

            <asp:Button ID="submit" Text="Submit" OnClick="btn_sub" runat="server" />

        </div>
    </form>
</body>
</html>
